/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:03:42 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/21 17:07:05 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
int main (void)
{
	DiamondTrap diamond("Diamond");
	diamond.show_status();
	diamond.attack("enemy");
	diamond.highFivesGuys();
	diamond.show_status();
	diamond.takeDamage(10);
	diamond.show_status();
	diamond.whoAmI();
}
