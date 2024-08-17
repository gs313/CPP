/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:19:09 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/04 01:53:17 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		//Orthodox Canonical Form
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		//Adding Constructor and overload << in 01
		Fixed(int const n);
		Fixed(float const n);

		//member function from 00
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		//added member function in 01
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int	_value;
		static const int	_fractional_bits;
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif
