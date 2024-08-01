/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 21:56:22 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/01 14:37:16 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int main (void)
{
	Harl harl;

	std::cout << std::endl << "------ DEBUG Level ------" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl << "------ INFO Level ------" << std::endl;;
	harl.complain("INFO");
	std::cout << std::endl << "------ WARNING Level ------" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl << "------ ERROR Level ------" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl << "------ No valid Level ------" << std::endl;
	harl.complain("ALARM");
	return (0);
}
