/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 21:56:22 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/01 15:06:40 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int main (int argc, char** argv)
{
	if (argc!=2)
	{
		std::cout << "ERROR: wrong number of input" << std::endl;
		return 0;
	}
	Harl harl;
	harl.complainfilter(argv[1]);
	return (0);

}
