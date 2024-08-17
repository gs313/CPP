/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:07:24 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/15 01:54:44 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
}
Point::Point(Point const &other)
{
	*this = other;
}
Point::Point(Fixed const x, Fixed const y): _x(x), _y(y)
{
}
Point &Point::operator=(Point const &other)
{
	(void) other;
	return *this;
}
Point::~Point()
{
}

Fixed Point::getX(void) const
{
	return this->_x;
}
Fixed Point::getY(void) const
{
	return this->_y;
}
