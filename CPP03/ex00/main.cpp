/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:03:42 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/21 12:48:03 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap claptrap("Conor");
	ClapTrap claptrap2(claptrap);
	ClapTrap claptrap3 = claptrap;

	claptrap.attack("John");
	claptrap.show_status();
	claptrap.takeDamage(5);
	claptrap.show_status();
	claptrap.beRepaired(3);
	claptrap.show_status();
	claptrap2.attack("John");
	claptrap2.show_status();
	claptrap2.takeDamage(5);
	claptrap2.show_status();
	claptrap2.beRepaired(3);
	claptrap2.show_status();
	claptrap3.attack("John");
	claptrap3.show_status();
	claptrap3.takeDamage(5);
	claptrap3.show_status();
	claptrap3.beRepaired(3);
	claptrap3.show_status();
	return (0);
}
