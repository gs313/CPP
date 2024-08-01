/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:23:05 by scharuka          #+#    #+#             */
/*   Updated: 2024/07/29 16:38:19 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// ./Zombie01 [name] [#zombies]
int	main (int argc, char** argv)
{
	Zombie*		horde;
	int			nb = 10;
	std::string	name = "annonymus";

	if (argc > 1)
		name = argv[1];
	if (argc > 2 && atoi(argv[2])>=0)
		nb = atoi(argv[2]);
	std::cout << "============= zombieHorde =============" << std::endl;
	horde = zombieHorde(nb, name);
	std::cout << nb << " zombies  have been created" << std::endl;
	for(int i =  0 ; i<nb ; i++ )
		horde[i].announce();
	delete [] horde;
	std::cout << "The horde of " << nb << " zombies has been eradicated." << std::endl;
	return (0);
}
