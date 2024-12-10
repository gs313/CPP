/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:34:30 by scharuka          #+#    #+#             */
/*   Updated: 2024/12/10 17:07:21 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45), _target("default") {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this == &copy)
		return (*this);
	_target = copy._target;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	srand(time(NULL));
	std::cout << "Drilling noises" << std::endl;
	if(rand() % 2)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
}
