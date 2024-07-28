/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:06:59 by scharuka          #+#    #+#             */
/*   Updated: 2024/07/28 18:04:16 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{}
Contact::~Contact()
{}
std::string	Contact::get_fname(void) const
{
	return(this->_fname);
}
std::string	Contact::get_lname(void) const
{
	return(this->_lname);
}
std::string	Contact::get_nname(void) const
{
	return (this->_nname);
}
std::string	Contact::get_pnum(void) const
{
	return (this->_pnum);
}
std::string	Contact::get_darksecret(void) const
{
	return (this->_darksecret);
}

void		Contact::set_fname(std::string str)
{
	this->_fname = str;
}
void		Contact::set_lname(std::string str)
{
	this->_lname = str;
}
void		Contact::set_nname(std::string str)
{
	this->_nname = str;
}
void		Contact::set_pnum(std::string str)
{
	this->_pnum = str;
}
void		Contact::set_darksecret(std::string str)
{
	this->_darksecret = str;
}
