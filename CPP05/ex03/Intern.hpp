/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:21:28 by scharuka          #+#    #+#             */
/*   Updated: 2024/12/10 21:58:54 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
#include  <map>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"

class Intern
{
private:
	AForm *createPresidentialPardonForm(std::string target);
	AForm *createRobotomyRequestForm(std::string target);
	AForm *createShrubberyCreationForm(std::string target);
public:
	Intern();
	~Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &copy);
	AForm *makeForm(std::string formName, std::string target);
	class FormNotFoundException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif