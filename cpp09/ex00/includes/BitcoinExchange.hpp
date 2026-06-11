#pragma once

#include <string>
#include <map>

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
