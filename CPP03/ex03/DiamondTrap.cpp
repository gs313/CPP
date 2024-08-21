/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:25:44 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/21 17:05:05 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	_name = ClapTrap::_name + "_clap_name";
	_hit_point = FragTrap::_hit_point;
	_energy_point = ScavTrap::_energy_point;
	_attack_damage = FragTrap::_attack_damage;

	std::cout << "DiamondTrap " << _name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	_name = ClapTrap::_name + "_clap_name";
	_hit_point = FragTrap::_hit_point;
	_energy_point = ScavTrap::_energy_point;
	_attack_damage = FragTrap::_attack_damage;

	std::cout << "DiamondTrap " << _name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " destroyed" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	_name = copy._name;
	_hit_point = copy._hit_point;
	_energy_point = copy._energy_point;
	_attack_damage = copy._attack_damage;
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::show_status(void)
{
	std::cout << "DiamondTrap " << _name << " status:" << std::endl;
	std::cout << "Hit points: " << _hit_point << std::endl;
	std::cout << "Energy points: " << _energy_point << std::endl;
	std::cout << "Attack damage: " << _attack_damage << std::endl;
}
