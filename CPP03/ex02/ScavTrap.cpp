/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:52:10 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/21 13:42:01 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Deconstructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap asignment operator called" << std::endl;
	this->_name = src._name;
	this->_hit_point = src._hit_point;
	this->_energy_point = src._energy_point;
	this->_attack_damage = src._attack_damage;
	return (*this);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Constructor with parameter \"name\" called" << std::endl;
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
}

void	ScavTrap::attack(const std::string& target)
{
	if(this->_hit_point == 0)
	{
		std::cout << "ScavTrap " << this->_name << " is dead and can't attack " << target << "!" << std::endl;
		return ;
	}
	if(this->_energy_point < 1)
	{
		std::cout << "ScavTrap " << this->_name << " has no energy to attack " << target << "!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_point--;
}

void	ScavTrap::show_status(void)
{
	std::cout << "ScavTrap " << this->_name << " has " << this->_hit_point << " hit points, " << this->_energy_point << " energy points and " << this->_attack_damage << " attack damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode!" << std::endl;
}
