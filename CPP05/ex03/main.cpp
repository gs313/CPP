/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 02:30:35 by scharuka          #+#    #+#             */
/*   Updated: 2024/12/10 22:10:41 by scharuka         ###   ########.fr       */
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
	Form *b =  a->makeForm("PresidentialPardonForm", "Clown");
	

}
