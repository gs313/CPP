/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 02:30:35 by scharuka          #+#    #+#             */
/*   Updated: 2024/12/10 21:09:39 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::cout << "\n ------------------------------------------------------------\n" << std::endl;
	std::cout << "PresidentialPardonForm" << std::endl;
	try
	{
		Bureaucrat b("Bureaucrat", 1);
		std::cout << b << std::endl;
		PresidentialPardonForm p("target");
		std::cout << p << std::endl;
		b.signForm(p);
		b.executeForm(p);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n ------------------------------------------------------------\n" << std::endl;
	std::cout << "RobotomyRequestForm" << std::endl;
	try
	{
		Bureaucrat b("Bureaucrat", 1);
		std::cout << b << std::endl;
		RobotomyRequestForm r("target");
		std::cout << r << std::endl;
		b.signForm(r);
		b.executeForm(r);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n ------------------------------------------------------------\n" << std::endl;
	std::cout << "ShrubberyCreationForm" << std::endl;
	try
	{
		Bureaucrat b("Bureaucrat", 149);
		std::cout << b << std::endl;
		ShrubberyCreationForm s("target");
		std::cout << s << std::endl;
		b.signForm(s);
		b.executeForm(s);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
