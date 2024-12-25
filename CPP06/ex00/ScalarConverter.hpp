/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:32:30 by scharuka          #+#    #+#             */
/*   Updated: 2024/12/25 21:21:56 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
# include <iostream>
#include <string>
#include <cmath>
#include <string>
#include <iomanip>

class ScalarConverter
{
	public:
		static void convert(const std::string& str);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &copy);

};

std::ostream &operator<<(std::ostream &out, const ScalarConverter &scalarConverter);

#endif
