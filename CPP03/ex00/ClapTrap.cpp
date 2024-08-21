/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:29:53 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/21 13:54:04 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("annonymous"), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = copy;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Deconstructor called" << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap asignment operator called" << std::endl;
	this->_name = src._name;
	this->_hit_point = src._hit_point;
	this->_energy_point = src._energy_point;
	this->_attack_damage = src._attack_damage;
	return (*this);
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	 std::cout << "ClapTrap Constructor with parameter \"name\" called" << std::endl;
}
void	ClapTrap::attack(const std::string& target)
{
	if(this->_hit_point == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and can't attack " << target << "!" << std::endl;
		return ;
	}
	if(this->_energy_point < 1)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy to attack " << target << "!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_point--;
}
void	ClapTrap::takeDamage(unsigned int	amount)
{
	if(this->_hit_point == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return ;
	}
	if(this->_hit_point < amount)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << this->_hit_point << " damage and dies!" << std::endl;
		this->_hit_point = 0;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage!" << std::endl;
	this->_hit_point -= amount;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if(this->_hit_point == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and can't be repaired!" << std::endl;
		return ;
	}
	if(this->_energy_point < 1)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy to be repaired!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " hit points!" << std::endl;
	this->_hit_point += amount;
	this->_energy_point--;
}

void	ClapTrap::show_status(void)
{
	std::cout << "ClapTrap " << this->_name << " has " << this->_hit_point << " hit points, " << this->_energy_point << " energy points and " << this->_attack_damage << " attack damage!" << std::endl;
}
