#include "BitcoinExchange.hpp"

#include <sstream>
#include <fstream>
#include <iostream>
#include <stdexcept>

template<typename T>
std::string to_string(const T & value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadExchangeRates(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Could not open file: " + filename);
	std::string line;
	std::getline(file, line); // Skip header line
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date;
		std::string rateStr;
		double rate;
		if (!(std::getline(iss, date, ',') && std::getline(iss, rateStr)))
		{
			throw std::runtime_error("Invalid line format in exchange rates file: " + line);
		}
		std::istringstream(rateStr) >> rate;
		if (rate < 0)
		{
			throw std::runtime_error("Negative exchange rate found for date: " + date);
		}
		_exchangeRates[date] = rate;
	}
	file.close();
	if (_exchangeRates.empty())
	{
		throw std::runtime_error("No valid exchange rates found in file: " + filename);
	}
	return;
}
double BitcoinExchange::getExchangeRate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = _exchangeRates.find(date);
	if (it != _exchangeRates.end())
		return it->second;
	else{
		std::map<std::string, double>::const_iterator itLower = _exchangeRates.lower_bound(date);
		if (itLower != _exchangeRates.begin())
		{
			--itLower;
			return itLower->second;
		}
		else
		{
			return -1.0;
		}
	}
}
void BitcoinExchange::processInput(const std::string& inputFile)
{
	std::ifstream input(inputFile.c_str());
	if (!input.is_open())
		throw std::runtime_error("Could not open input file: " + inputFile);
	std::string line;
	std::getline(input, line);
	if (line != "date | value")
	{
		throw std::runtime_error("Invalid header in input file: " + line);
	}
	while (std::getline(input, line))
	{
		std::istringstream iss(line);
		std::string date;
		double value = 0.0;
		char comma;
		if (!(iss >> date >> comma >> value))
		{
			std::cerr << "Invalid line format in input file: " << line << std::endl;
			continue;
		}
		if (comma != '|')
		{
			std::cerr << "Invalid separator in input file: " << line << std::endl;
			continue;
		}
		if (validateDate(date) == -1)
		{
			continue;
		}
		if (validateValue(value) == -1)
		{
			continue;
		}
		double rate = getExchangeRate(date);
		if (rate < 0.0)
		{
			continue;
		}
		std::cout << date << " => " << value << " * " << rate << " = " << (rate *value) << std::endl;
	}
	input.close();


}
int BitcoinExchange::validateDate(const std::string& date) const
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cerr << "Invalid date format: " << date << std::endl;
		return -1;
	}
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	if (year < "2009" || year > "2023" || month < "01" || month > "12" || day < "01" || day > "31")
	{
		std::cerr << "Date out of range: " << date << std::endl;
		return -1;
	}
	return 0;
}
int BitcoinExchange::validateValue(double value) const
{
	if (value < 0)
	{
		std::cerr << "Negative value found: " << to_string(value) << std::endl;
		return -1;
	}
	if (value > 1000)
	{
		std::cerr << "Value exceeds maximum limit: " << to_string(value) << std::endl;
		return -1;
	}
	return 0;
}

