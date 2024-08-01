/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 21:56:28 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/01 15:08:38 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{}
Harl::~Harl(void)
{}
void Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do" << std::endl;
}
void Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning (void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void Harl::complainfilter (std::string l)
{
	std::string level[] = {"DEBUG", "INFO", "WARNING","ERROR"};
	void (Harl::*ft[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i;
	for (i = 0; i < 4 ; i++)
	{
		if(l == level[i])
			break;
	}
	switch (i)
	{
	case 0:
		(this->*ft[0])();
		std::cout <<std::endl;
	case 1:
		(this->*ft[1])();
		std::cout <<std::endl;

	case 2:
		(this->*ft[2])();
		std::cout <<std::endl;
	case 3:
		(this->*ft[3])();
		std::cout <<std::endl;
		break;

	default:
		std::cout << "[ Probably complaining about insignificant problems ]"<<std::endl;
	}
}
