/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:05:55 by scharuka          #+#    #+#             */
/*   Updated: 2024/07/28 21:26:41 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_num_contact = 0;
	std::cout << BOLDBLUE"A Phone Book is created. Up to 8 contacts can be stored\n"<<RESET;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << BOLDRED"The phone book are deleted\n"<<RESET;
}

int		PhoneBook::check_type(std::string str, std::string type)
{
	int	len = str.length();
	if(str.empty())
	{
		std::cout << BOLDRED"No field should be empty\n"<<RESET;
		return (0);
	}
	if(type == "number")
	{
		for(int i = 0; i<len; i++)
		{
			if(!isdigit(str[i]))
			{
				std::cout << BOLDRED"Please input \"Numbers\" only\n"<<RESET;
				return (0);
			}
		}
	}
	else if(type == "letter")
	{
		for(int i = 0; i<len; i++)
		{
			if(!isalpha(str[i]))
			{
				std::cout << BOLDRED"Please input \"Alphabets\" only\n"<<RESET;
				return (0);
			}
		}
	}
	else if(type == "secret")
	{
		for(int i = 0; i<len; i++)
		{
			if(!isalpha(str[i]) && !isspace(str[i]) && !isdigit(str[i]))
			{
				std::cout << BOLDRED"Please input \"words\" and/or \"numbers\"\n"<<RESET;
				return (0);
			}
		}
	}
	return (1);
}

void PhoneBook::add(void)
{
	std::string	tmpstr;

	tmpstr = "";

	if (this->_num_contact > 7)
		std::cout << BOLDRED"Warning: this wil overwrite the info of "
			<< this->_book[this->_num_contact%8].get_fname() << " "
			<< this->_book[this->_num_contact%8].get_lname() << std::endl <<RESET;
	while(!std::cin.eof() && tmpstr == "")
	{
		std::cout << BLUE"Enter a first name: "<<RESET;
		if (std::getline(std::cin, tmpstr) && check_type(tmpstr,"letter"))
		{
			this->_book[this->_num_contact%8].set_fname(tmpstr);
		}
		else
			tmpstr = "";
	}
	tmpstr="";
	while(!std::cin.eof() && tmpstr == "")
	{
		std::cout << BLUE"Enter a last name: "<<RESET;
		if (std::getline(std::cin, tmpstr) && check_type(tmpstr,"letter"))
		{
			this->_book[this->_num_contact%8].set_lname(tmpstr);
		}
		else
			tmpstr = "";
	}
	tmpstr="";
	while(!std::cin.eof() && tmpstr == "")
	{
		std::cout << BLUE"Enter a nickname: "<<RESET;
		if (std::getline(std::cin, tmpstr) && check_type(tmpstr,"letter"))
		{
			this->_book[this->_num_contact%8].set_nname(tmpstr);
		}
		else
			tmpstr = "";
	}
	tmpstr="";
	while(!std::cin.eof() && tmpstr == "")
	{
		std::cout << BLUE"Enter a phone number: "<<RESET;
		if (std::getline(std::cin, tmpstr) && check_type(tmpstr,"number"))
		{
			this->_book[this->_num_contact%8].set_pnum(tmpstr);
		}
		else
			tmpstr = "";
	}
	tmpstr="";
	while(!std::cin.eof() && tmpstr == "")
	{
		std::cout << BLUE"Enter a dark secret: "<<RESET;
		if (std::getline(std::cin, tmpstr) && check_type(tmpstr,"secret"))
		{
			this->_book[this->_num_contact%8].set_darksecret(tmpstr);
		}
		else
			tmpstr = "";
	}
	this->_num_contact++;
}

std::string	PhoneBook::check_fixlen(std::string str)
{
	if(str.length() > 10)
		return (str.substr(0,9) + ".");
	return (str);
}

void	PhoneBook::display_contacts(void)
{
	std::cout << MAGENTA"---------------------------------------------\n";
	std::cout << MAGENTA"|     Index| Firstname|  Lastname|  Nickname|\n";
	std::cout << MAGENTA"---------------------------------------------\n";
	int max = this->_num_contact;
	if (max > 8)
		max = 8;
	for (int i = 0; i < max; i++)
	{
		std::cout << MAGENTA"|" << WHITE << std::setw(10) << std::right << i << MAGENTA"|";
		std::cout << WHITE << std::setw(10) << std::right << check_fixlen(this->_book[i].get_fname()) << MAGENTA"|";
		std::cout << WHITE << std::setw(10) << std::right << check_fixlen(this->_book[i].get_lname()) << MAGENTA"|";
		std::cout << WHITE << std::setw(10) << std::right << check_fixlen(this->_book[i].get_nname()) << MAGENTA"|";
		std::cout << std::endl;
	}
	std::cout << MAGENTA"---------------------------------------------\n" << RESET;
}

void	PhoneBook::search(void)
{
	if(this->_num_contact == 0)
	{
		std::cout << WHITE"There is no contact in the phone book\n";
		return ;
	}
	display_contacts();

	std::cout << BLUE"Choose index that you wanna see\n Index:";
	int input;
	std::cin >> input;
	if (std::cin.fail() || input > 8 || input < 0 || input >= this->_num_contact)
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << BOLDRED << "ERROR: the index does not exist!" << RESET << std::endl;
		return ;
	}
	else
	{
		std::cout << BOLDBLUE;
		std::cout << "First name: " << _book[input].get_fname() << std::endl;
		std::cout << "Lastname: " << _book[input].get_lname() << std::endl;
		std::cout << "Nickname: "<< _book[input].get_nname() << std::endl;
		std::cout << "Phone number: " << _book[input].get_pnum() << std::endl;
		std::cout << "Dark Secret: "<< _book[input].get_darksecret() << std::endl<<RESET;
		std::cin.ignore(10000, '\n');
	}
}
