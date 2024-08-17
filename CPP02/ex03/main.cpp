/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:19:11 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/17 17:22:25 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) {
	std::cout << std::boolalpha
		<< "(0,0), (1,0), (1,1) -> target (1,1) - On vertex:"
		<< bsp(Point(0,0), Point (1, 0), Point (1, 1), Point(1,1)) << std::endl
		<< "(0,0), (10,0), (0,5) -> target (1,1) - inside:"
		<< bsp(Point(0,0), Point (10, 0), Point (0, 5), Point(1,1)) << std::endl
		<< "(0,0), (10,0), (0,5) -> target (1,1) - out side:"
		<< bsp(Point(0,0), Point (10, 0), Point (0, 5), Point(20,20)) << std::endl;
		std::cout << "sdsdsdsds " << bsp(Point(0,0), Point(1,1), Point(0,2), Point(0,2.5f)) << std::endl;
	return 0;
}
