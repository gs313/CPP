/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:13:10 by scharuka          #+#    #+#             */
/*   Updated: 2024/07/30 02:25:43 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon	*_weapon;
	public:
		HumanB(std::string	name);
		~HumanB();
		void	attack(void) const;
		void	setWeapon(Weapon &weapon);
};

#endif
