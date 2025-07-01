#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <stdexcept>

class BitcoinExchange
{
private:
	std::map<std::string, double> _exchangeRates;
public:
	BitcoinExchange();
	~BitcoinExchange();
	void loadExchangeRates(const std::string& filename);
	double getExchangeRate(const std::string& date) const;
	void processInput(const std::string& inputFile);
	int validateDate(const std::string& date) const;
	int validateValue(double value) const;
};




#endif
