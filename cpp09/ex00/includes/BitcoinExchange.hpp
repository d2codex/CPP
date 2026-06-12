#pragma once

#include <string>
#include <map>

/**
 * @brief Manages Bitcoin exchange rate data loaded from a CSV database
 *        and provides date-based rate lookups for value conversions.
 */
class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();

	void	processInput(const std::string& filename);
	double	getRate(const std::string& date) const;

private:
	// canonical form but no use having them
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);

	void	loadDatabase(const std::string& filename);
	bool	isValidDate(const std::string& date) const;
	bool	isValidValue(double value) const;

	std::map<std::string, double> _rates;
};
