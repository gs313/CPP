/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:19:09 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/06 19:55:59 by scharuka         ###   ########.fr       */
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

		//overload operator 02
		bool operator>(const Fixed other) const;
		bool operator>=(const Fixed other) const;
		bool operator<(const Fixed other) const;
		bool operator<=(const Fixed other) const;
		bool operator==(const Fixed other) const;
		bool operator!=(const Fixed other) const;

		//arithmatic operator 02
		float operator+(const Fixed other) const;
		float operator-(const Fixed other) const;
		float operator*(const Fixed other) const;
		float operator/(const Fixed other) const;

		//increment operator 02
		Fixed operator++(void);//prefix - void
		Fixed operator--(void);
		Fixed operator++(int); // postfix
		Fixed operator--(int);

		//member function from 00
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		//added member function in 01
		float	toFloat( void ) const;
		int		toInt( void ) const;

		//public funcrion from
		static Fixed &min(Fixed &first, Fixed &second);
		static Fixed &max(Fixed &first, Fixed &second);
		static const Fixed &min(const Fixed &first,const Fixed &second);
		static const Fixed &max(const Fixed &first,const Fixed &second);

	private:
		int	_value;
		static const int	_fractional_bits;
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif
