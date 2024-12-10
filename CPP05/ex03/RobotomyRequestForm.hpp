/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:34:52 by scharuka          #+#    #+#             */
/*   Updated: 2024/12/10 17:18:21 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

class AForm;
class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		void execute(const Bureaucrat &executor) const;
};

#endif
