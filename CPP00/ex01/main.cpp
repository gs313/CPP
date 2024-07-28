/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:07:01 by scharuka          #+#    #+#             */
/*   Updated: 2024/07/28 20:59:51 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string	cmd;
	PhoneBook myphonebook;

	while(!std::cin.eof())
	{
		std::cout << BOLDWHITE"PhoneBook :: "<<RESET;
		std::getline(std::cin, cmd);
		if(cmd.compare("EXIT") == 0)
		{
			break; /*do I need to delete anything?*/
		}
		else if(cmd.compare("ADD") == 0)
		{
			myphonebook.add();
		}
		else if(cmd.compare("SEARCH") == 0)
		{
			myphonebook.search();
		}
		else
			std::cout << BOLDRED"INVALID COMMAND (valid command include ADD, SEARCH and EXIT)\n";
	}
	return(0);
}
