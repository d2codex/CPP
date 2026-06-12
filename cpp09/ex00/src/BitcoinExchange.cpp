#include "BitcoinExchange.hpp"
#include <string>
#include <fstream>
#include <cerrno>
#include <map>
#include <cstdlib>
#include <iostream>

namespace {
/// Path to the Bitcoin exchange rate database file.
const char* DATABASE_FILE = "data.csv";
/// Characters considered whitespace for string trimming.
const std::string WHITESPACE = " \t\n\r\f\v";

/**
 * @brief Removes leading and trailing whitespace from a string.
 * @param str String to trim.
 */
void trim(std::string& str) {
	std::string::size_type start = str.find_first_not_of(WHITESPACE);
	std::string::size_type end = str.find_last_not_of(WHITESPACE);

	if (start == std::string::npos) {
		str.clear();
		return;
	}
	str = str.substr(start, end - start + 1);
}

/**
 * @brief Checks whether a string contains only digits.
 * @param str String to check.
 * @return true if the string contains only digits, false otherwise.
 */
bool isDigits(std::string& str) {
	for (size_t i = 0; i < str.size(); i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

/**
 * @brief Returns the number of days in a given month.
 * @param year Year used to determine leap years.
 * @param month Month in the range [1, 12].
 * @return Number of days in the month.
 */
int daysInMonth(int year, int month) {
	switch (month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
		case 4: case 6: case 9: case 11:
			return 30;
		case 2:
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
				return 29;
			return 28;
	}
	return 0;
}

/**
 * @brief Converts a string to a double.
 * @param str String to convert.
 * @return Converted double value.
 * @throws std::runtime_error If the string is invalid or overflows.
 */
double strToDouble(const std::string& str) {
	char *end;
	errno = 0;
	double value = std::strtod(str.c_str(), &end);

	if (errno == ERANGE)
		throw std::runtime_error("Overflow");
	if (end == str.c_str() || *end != '\0')
		throw std::runtime_error("Invalid number");
	return value;
}

} // end namespace

/**
 * @brief Constructs a BitcoinExchange and loads the exchange rate database.
 */
BitcoinExchange::BitcoinExchange() {
	loadDatabase(DATABASE_FILE);
}

/**
 * @brief Disabled copy constructor.
 * Present only to satisfy the Orthodox Canonical Form.
 */
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*(void)other;
}

/**
 * @brief Disabled assignment operator.
 * Present only to satisfy the Orthodox Canonical Form.
 */
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	(void)other;
	return *this;
}

/**
 * @brief Destroys the BitcoinExchange.
 */
BitcoinExchange::~BitcoinExchange() {
}

/**
 * @brief Loads and validates exchange rate data from a CSV file.
 *
 * Ensures format correctness, validates dates and rates, and prevents
 * duplicate dates in the database.
 *
 * @param filename Database file to load.
 * @throws std::runtime_error If the file cannot be read or contains
 *         malformed data (including duplicate dates or bad header).
 * @throws std::invalid_argument If a date is invalid.
 */
void BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file)
		throw std::runtime_error("Could not open file");
	
	std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("File is empty");

	if (line != "date,exchange_rate")
		throw std::runtime_error("Invalid database header");

	while (getline(file, line)) {
		std::size_t comma = line.find(',');
		if (comma == std::string::npos)
			throw std::runtime_error("Malformed database line: " + line);

		std::string date = line.substr(0, comma);
		trim(date);
		if (!isValidDate(date))
			throw std::invalid_argument("Invalid date: " + date);

		std::string rateStr = line.substr(comma + 1);
		trim(rateStr);
		double rate = strToDouble(rateStr);
	
		std::pair<std::map<std::string, double>::iterator, bool> result;
		result = _rates.insert(std::make_pair(date, rate));
		if (!result.second)
			throw std::runtime_error("Duplicate date in database: " + date);
	}
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	//YYYY-MM-DD
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	std::string y = date.substr(0, 4);
	std::string m = date.substr(5, 2);
	std::string d = date.substr(8, 2);

	if (!isDigits(y) || !isDigits(m) || !isDigits(d))
		return false;
	
	int year = std::atoi(y.c_str());
	int month = std::atoi(m.c_str());
	int day = std::atoi(d.c_str());

	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	if (day > daysInMonth(year, month))
		return false;

	return true;
}

/**
 * @brief Validates a date string in YYYY-MM-DD format.
 *
 * Checks format correctness, numeric fields, and calendar validity
 * (including month length and leap years).
 *
 * @param date Date string to validate.
 * @return true if the date is valid, false otherwise.
 */
bool BitcoinExchange::isValidValue(double value) const {
	if (value < 0) {
		std::cerr << "Error: not a positive number.\n";
		return false;
	}
	if (value > 1000) {
		std::cerr << "Error: too large a number.\n";
		return false;
	}
	return true;
}

/**
 * @brief Processes an input file and performs Bitcoin value conversions.
 *
 * Reads a file containing lines in the format `date | value`, validates
 * each entry, and outputs the converted result using stored exchange rates.
 *
 * Input lines are validated individually; malformed lines are skipped
 * with an error message. The file header is ignored and not validated.
 *
 * @param filename Input file to process.
 * @throws std::runtime_error If the file cannot be opened or is empty.
 */
void BitcoinExchange::processInput(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file)
		throw std::runtime_error("Could not open file");
	std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("File is empty");
	
	while (std::getline(file, line)) {
		std::size_t separator = line.find('|');
		if (separator == std::string::npos) {
			std::cerr << "Error: bad input => " + line << std::endl;
			continue;
		}
		std::string date = line.substr(0, separator);
		trim(date);
		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " + line << std::endl;
			continue;
		}
		std::string valueStr = line.substr(separator + 1);
		trim(valueStr);
		double value;
		try {
			value = strToDouble(valueStr);
		}
		catch (const std::exception& e) {
			std::cerr << "bad input => " << line << std::endl;
			continue;
		}
		if (!isValidValue(value))
			continue;
		try {
			double rate = getRate(date);
			double result = rate * value;
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
			continue;
		}
	}
}

/**
 * @brief Retrieves the Bitcoin exchange rate for a given date.
 *
 * Finds the closest available rate for the requested date.
 * If an exact match is not found, returns the most recent
 * previous date's rate.
 *
 * @param date Date in YYYY-MM-DD format.
 * @return Exchange rate for the given date or nearest earlier date.
 * @throws std::runtime_error If the date is earlier than any stored rate.
 */
double BitcoinExchange::getRate(const std::string& date) const {
	std::map<std::string, double>::const_iterator it;
	it = _rates.upper_bound(date);
	if (it == _rates.begin())
		throw::std::runtime_error("Date too early");
	--it;
	return it->second;
}
