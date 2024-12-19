/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 02:30:35 by scharuka          #+#    #+#             */
/*   Updated: 2024/12/11 21:38:08 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "\n ------------------------------------------------------------\n" << std::endl;
	std::cout << "Intern create a valid form " << std::endl;
	Intern *a = new Intern();
	AForm *b =  a->makeForm("PresidentialPardonForm", "Clown");
	std::cout << *b << std::endl;
	Bureaucrat c("Bureaucrat", 1);
	std::cout << c << std::endl;
	c.signForm(*b);
	c.executeForm(*b);
	std::cout << *b << std::endl;

	std::cout << "\n ------------------------------------------------------------\n" << std::endl;
	std::cout << "Intern create a invalid form " << std::endl;
	try
	{
		AForm *c =  a->makeForm("InvalidForm", "Clown");
		std::cout << *c << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


}
