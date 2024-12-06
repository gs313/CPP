/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 02:30:35 by scharuka          #+#    #+#             */
/*   Updated: 2024/12/06 18:10:17 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "\n ------------------------------------------------------------\n" << std::endl;
	std::cout << "Form test: can sign" << std::endl;
	try
	{
		Form form("Form", 1, 1);
		std::cout << form << std::endl;
		Bureaucrat bureaucrat("Bureaucrat", 1);
		std::cout << bureaucrat;
		bureaucrat.signForm(form);
		std::cout << form;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n ------------------------------------------------------------\n" << std::endl;
	std::cout << "Form test: can't sign" << std::endl;
	try
	{
		Form form("Form", 1, 1);
		std::cout << form << std::endl;
		Bureaucrat bureaucrat("Bureaucrat", 150);
		std::cout << bureaucrat;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
