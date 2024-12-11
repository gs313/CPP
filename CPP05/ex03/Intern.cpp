/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:21:24 by scharuka          #+#    #+#             */
/*   Updated: 2024/12/10 21:59:03 by scharuka         ###   ########.fr       */
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
    std::map<std::string, AForm* (Intern::*)(std::string)> formCreators = {
        {"PresidentialPardonForm", &Intern::createPresidentialPardonForm},
        {"RobotomyRequestForm", &Intern::createRobotomyRequestForm},
        {"ShrubberyCreationForm", &Intern::createShrubberyCreationForm}
    };

    // Find the form creator in the map
    auto it = formCreators.find(formName);
    if (it != formCreators.end()) {
        AForm *form = (this->*(it->second))(target);
        std::cout << "Intern creates " << *form << std::endl;
        return form;
    }

    throw FormNotFoundException();
}