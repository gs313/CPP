/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:16:57 by scharuka          #+#    #+#             */
/*   Updated: 2024/07/30 00:42:12 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv)
{
	if(argc != 1 && argv[1] != NULL)
		std::cout << "* there are no need for extra argument, so the extra argument will be ignore *\n";
	//the first two is stack way of storing zombie while newZombie is heap (don't for get to delete it!)
	std::cout << "============= Zombie =============" << std::endl;
	Zombie	zom1("red");
	Zombie	zom2("green");
	Zombie	zom3;

	zom1.announce();
	zom2.announce();
	zom3.announce();
	std::cout << "============= randomChump =============" << std::endl;

	randomChump("random");

	std::cout << "============= newZombie =============" << std::endl;

	Zombie *newz;
	newz = newZombie("newcommer");
	newz->announce();
	delete(newz);

	return(0);
}
