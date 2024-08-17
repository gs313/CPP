/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:19:01 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/04 04:15:32 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

const int Fixed:: _fractional_bits = 8;

Fixed::Fixed(): _value(0)
{
	std::cout << "Default construtor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	_value = n << _fractional_bits; // calling the variable or this->variable is the same here
}
Fixed::Fixed(float const n)
{
	std::cout << "Float constructor called" << std::endl;
	_value = (roundf( n * ( 1 << _fractional_bits)));
}

Fixed::~Fixed()
{
	std::cout << "Deconstructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();

	return *this;
}

int		Fixed::getRawBits(void) const
{
	return(this->_value);
}
void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return((float) this->_value / float(1<<this->_fractional_bits));
}

int		Fixed::toInt( void ) const
{
	return(this->_value >> this->_fractional_bits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
