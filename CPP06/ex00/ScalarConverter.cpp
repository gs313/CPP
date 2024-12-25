/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:47:57 by scharuka          #+#    #+#             */
/*   Updated: 2024/12/25 21:22:57 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
bool caseSciNotation(const std::string &str);
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
	static double _double = std::stod(str);
	static float _float = static_cast<float>(_double);
	static int _int = static_cast<int>(_double);
	static char _char = static_cast<char>(_double);

	if (_char < 32 || _char > 126)
	{
		std::cout << "char: Non displayable" << std::endl;
	}
	else
	{
		std::cout << "char: " << _char << std::endl;
	}
	std::cout << "int: " << _int << std::endl;
	std::cout << std::setprecision(1) << "float: " << _float << "f" << std::endl;
	std::cout << std::setprecision(1) << "double: " << _double << std::endl;
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

	else if (!str.compare("nanf"))
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
