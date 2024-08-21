/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:03:42 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/21 13:44:56 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main (void)
{
	ClapTrap claptrap("Claptrap");
	ScavTrap scavtrap("Scavtrap");

	claptrap.attack("enemy");
	claptrap.takeDamage(10);
	claptrap.beRepaired(5);
	claptrap.show_status();
	scavtrap.attack("enemy");
	scavtrap.takeDamage(10);
	scavtrap.beRepaired(5);
	scavtrap.show_status();
	scavtrap.guardGate();
	return (0);
}
