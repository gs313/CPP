/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 02:30:35 by scharuka          #+#    #+#             */
/*   Updated: 2024/12/06 16:29:13 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\n ------------------------------------------------------------\n" << std::endl;
	std::cout << "Case: creating with invalid grade\n" << std::endl;
	try {
		Bureaucrat bureaucrat("John", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat bureaucrat("John", 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n ------------------------------------------------------------\n" << std::endl;
	std::cout << "Case: Incrementing and decrementing grade\n" << std::endl;
	try{
		Bureaucrat bureaucrat("John", 150);
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n ------------------------------------------------------------\n" << std::endl;
	std::cout << "Case: Incrementing until exception\n" << std::endl;
	try{
		Bureaucrat bureaucrat("John", 5);
		while (true) {
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade();
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n ------------------------------------------------------------\n" << std::endl;
	std::cout << "Case: Decrementing until exception\n" << std::endl;
	try{
		Bureaucrat bureaucrat("John", 145);
		while (true) {
			std::cout << bureaucrat << std::endl;
			bureaucrat.decrementGrade();
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
