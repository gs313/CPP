/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:33:43 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/21 13:48:51 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>

class ClapTrap
{
	public:
	// Orthodox Canonical Form
		ClapTrap();
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &src);

		ClapTrap(std::string name);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int	amount);
		void	beRepaired(unsigned int amount);
		void	show_status(void);
	protected:
		std::string	_name;
		unsigned int		_hit_point;
		unsigned int		_energy_point;
		unsigned int		_attack_damage;
};
#endif
