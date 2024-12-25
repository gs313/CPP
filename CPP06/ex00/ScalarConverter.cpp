/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:47:57 by scharuka          #+#    #+#             */
/*   Updated: 2024/12/25 21:41:49 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
bool caseSciNotation(const std::string &str);
bool caseNotNumber(const std::string &str);
ScalarConverter::ScalarConverter()
{

}
ScalarConverter::~ScalarConverter()
{

}
ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	if (this != &copy)
		*this = copy;
	return (*this);
}

void ScalarConverter::convert(const std::string &str)
{
	if (caseSciNotation(str))
		return;
	static char _char = str[0];
	static int _int = static_cast<int>(_char);
	static float _float = static_cast<float>(_char);
	static double _double = static_cast<double>(_char);
	if (!caseNotNumber(str))
	{
		_double = std::stod(str);
		_float = static_cast<float>(_double);
		_int = static_cast<int>(_double);
		_char = static_cast<char>(_double);
	}

	if (_char < 32 || _char > 126)
	{
		std::cout << "char: Non displayable" << std::endl;
	}
	else
	{
		std::cout << "char: '" << _char << "'" << std::endl;
	}
	std::cout << "int: " << _int << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << _float << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << _double << std::endl;
}

bool caseSciNotation(const std::string &str)
{
	if (!str.compare("+inff") || !str.compare("+inf"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return (true);
	}

	else if (!str.compare("-inff") || !str.compare("-inf"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return (true);
	}

	else if (!str.compare("nanf") || !str.compare("nan"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (true);
	}
	else
	{
		return (false);
	}
}
bool caseNotNumber(const std::string &str)
{
	int i = 0;
	bool nodot = 1;
	bool nof = 1;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.' && nodot)
		{
			nodot = 0;
			i++;
			continue;
		}
		else if (str[i] == 'f' && nof)
		{
			nof = 0;
			i++;
			continue;
		}
		else if (!std::isdigit(str[i]))
			return (true);
		i++;
	}
	return (false);
}