/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:12:49 by scharuka          #+#    #+#             */
/*   Updated: 2024/07/30 02:25:05 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon	&_weapon;
	public:
		HumanA(std::string	name, Weapon &weapon);
		~HumanA();
		void	attack(void) const;
};

#endif
