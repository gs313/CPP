/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:03:42 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/21 14:21:11 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
int main (void)
{
	FragTrap frag("Frag");
	frag.attack("enemy");
	frag.highFivesGuys();
	frag.show_status();
	frag.takeDamage(10);
	frag.show_status();
}
