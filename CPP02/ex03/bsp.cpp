/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:07:32 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/17 15:21:03 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point point)
{
	bool	sign[3];

	sign[0] = ((a.getX() - point.getX()) * (b.getY() - a.getY()) - (a.getY() - point.getY()) *( b.getX() - a.getX())) > 0;
	sign[1] = ((b.getX() - point.getX()) * (c.getY() - b.getY()) - (b.getY() - point.getY()) *( c.getX() - b.getX())) > 0;
	sign[2] = ((c.getX() - point.getX()) * (a.getY() - c.getY()) - (c.getY() - point.getY()) *( a.getX() - c.getX())) > 0;

	return sign[0] == sign[1] && sign[1] == sign[2];
}
