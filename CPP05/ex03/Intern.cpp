/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:21:24 by scharuka          #+#    #+#             */
/*   Updated: 2024/12/11 21:33:58 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

const char* Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}

AForm *Intern::createPresidentialPardonForm(std::string target){
	return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string target){
	return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyCreationForm(std::string target){
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target) {
    std::map<std::string, AForm* (Intern::*)(std::string)> formCreators;
    formCreators.insert(std::make_pair("PresidentialPardonForm", &Intern::createPresidentialPardonForm));
    formCreators.insert(std::make_pair("RobotomyRequestForm", &Intern::createRobotomyRequestForm));
    formCreators.insert(std::make_pair("ShrubberyCreationForm", &Intern::createShrubberyCreationForm));

    std::map<std::string, AForm* (Intern::*)(std::string)>::iterator it = formCreators.find(formName);
    if (it != formCreators.end()) {
        AForm *form = (this->*(it->second))(target);
        std::cout << "Intern creates " << *form << std::endl;
        return form;
    }

    throw FormNotFoundException();
}
