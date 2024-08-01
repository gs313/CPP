/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:12:44 by scharuka          #+#    #+#             */
/*   Updated: 2024/07/30 02:21:11 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string	name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	return ;
}
HumanA::~HumanA()
{
	return ;
}
void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with his/her " << this->_weapon.getType() << std::endl ;
}
