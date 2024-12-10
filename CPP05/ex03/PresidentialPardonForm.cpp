/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:33:06 by scharuka          #+#    #+#             */
/*   Updated: 2024/12/10 16:43:35 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5), _target("default") {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target) {}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this == &copy)
		return (*this);
	_target = copy._target;
	return (*this);
}
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
