/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:52:06 by scharuka          #+#    #+#             */
/*   Updated: 2024/12/10 16:49:40 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;
public:
	AForm();
	virtual ~AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &copy);
	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(const Bureaucrat &executor) const = 0;
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);


#endif
