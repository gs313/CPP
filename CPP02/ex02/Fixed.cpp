/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:19:01 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/07 02:41:59 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

const int Fixed:: _fractional_bits = 8;

Fixed::Fixed(): _value(0)
{
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::Fixed(int const n)
{
	_value = n << _fractional_bits; // calling the variable or this->variable is the same here
}
Fixed::Fixed(float const n)
{
	_value = (roundf( n * ( 1 << _fractional_bits)));
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &src)
{
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

//02

//overload operator 02
bool Fixed::operator>(const Fixed other) const
{
	return (this->toFloat() > other.toFloat());
}
bool Fixed::operator>=(const Fixed other) const
{
	return (this->toFloat() >= other.toFloat());
}
bool Fixed::operator<(const Fixed other) const
{
	return (this->toFloat() < other.toFloat());
}
bool Fixed::operator<=(const Fixed other) const
{
	return (this->toFloat() <= other.toFloat());

}
bool Fixed::operator==(const Fixed other) const
{
	return (this->toFloat() == other.toFloat());
}
bool Fixed::operator!=(const Fixed other) const
{
	return (this->toFloat() != other.toFloat());
}

//arithmatic operator 02
float Fixed::operator+(const Fixed other) const
{
	return (this->toFloat() + other.toFloat());
}
float Fixed::operator-(const Fixed other) const
{
	return (this->toFloat() - other.toFloat());
}
float Fixed::operator*(const Fixed other) const
{
	return (this->toFloat() * other.toFloat());
}
float Fixed::operator/(const Fixed other) const
{
	return (this->toFloat() / other.toFloat());

}

//increment operator 02
//prefix - void
Fixed Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}
Fixed Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}
// postfix
Fixed Fixed::operator++(int)
{
	Fixed tmp =*this;
	this->_value++;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed tmp =*this;
	this->_value--;
	return (*this);
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	return first < second ? first : second;
}
Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	return first > second ? first : second;
}
const Fixed &Fixed::min(const Fixed &first,const Fixed &second)
{
	return first < second ? first : second;
}
const Fixed &Fixed::max(const Fixed &first,const Fixed &second)
{
	return first > second ? first : second;
}
