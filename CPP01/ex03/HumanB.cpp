/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:13:12 by scharuka          #+#    #+#             */
/*   Updated: 2024/07/30 02:27:18 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string	name) : _name(name), _weapon(NULL)
{
	return ;
}
HumanB::~HumanB()
{
	return ;
}
void	HumanB::attack(void) const
{
	if(this->_weapon == NULL)
	{
		std::cout << this->_name << " cannot attract without weapon" << std::endl;
	}
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

