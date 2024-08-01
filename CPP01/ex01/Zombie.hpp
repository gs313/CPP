/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:17:03 by scharuka          #+#    #+#             */
/*   Updated: 2024/07/29 16:37:24 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <cstdlib>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie(std::string name);
		Zombie();
		~Zombie();
		void announce(void);
		void set_name(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
