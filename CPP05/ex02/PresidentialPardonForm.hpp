/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:34:42 by scharuka          #+#    #+#             */
/*   Updated: 2024/12/10 16:37:03 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;
class Beureaucrat;

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
	void execute(const Bureaucrat &executor) const;
};

#endif
