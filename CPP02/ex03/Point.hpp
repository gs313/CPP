/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:07:06 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/15 01:56:15 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"
class Point
{
	public:
	//Orthodox Canonical Form
		Point();
		Point(Point const &other);
		Point(Fixed const x, Fixed const y);
		Point &operator=(Point const &other);
		~Point();

		Fixed getX(void) const;
		Fixed getY(void) const;
	private:
		Fixed const	_x;
		Fixed const	_y;
};

bool bsp(Point const a, Point const b, Point const c, Point t);
#endif
