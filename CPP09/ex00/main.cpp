#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << "<input_file>" << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange exchange;
		exchange.loadExchangeRates("data.csv");
		exchange.processInput(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
