/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 02:30:35 by scharuka          #+#    #+#             */
/*   Updated: 2024/12/10 16:47:59 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "\n ------------------------------------------------------------\n" << std::endl;
	std::cout << "PresidentialPardonForm" << std::endl;
	try
	{
		Bureaucrat b("Bureaucrat", 1);
		PresidentialPardonForm p("target");
		std::cout << p << std::endl;
		b.signForm(p);
		b.executeForm(p);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
