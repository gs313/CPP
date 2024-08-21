/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:55:56 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/21 14:19:28 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default Constructor called" << std::endl;
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
}
FragTrap::FragTrap(const FragTrap &copy)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
	*this = copy;
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap Deconstructor called" << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap asignment operator called" << std::endl;
	this->_name = src._name;
	this->_hit_point = src._hit_point;
	this->_energy_point = src._energy_point;
	this->_attack_damage = src._attack_damage;
	return (*this);
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap Constructor with parameter \"name\" called" << std::endl;
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " high fives guys!" << std::endl;
}

void	FragTrap::show_status(void)
{
	std::cout << "FragTrap " << this->_name << " has " << this->_hit_point << " hit points, " << this->_energy_point << " energy points and " << this->_attack_damage << " attack damage!" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if(this->_hit_point == 0)
	{
		std::cout << "FragTrap " << this->_name << " is dead and can't attack " << target << "!" << std::endl;
		return ;
	}
	if(this->_energy_point < 1)
	{
		std::cout << "FragTrap " << this->_name << " has no energy to attack " << target << "!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing "<< this->_attack_damage <<" points of damage!" << std::endl;
	this->_energy_point--;
}
