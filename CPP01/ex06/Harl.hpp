/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 21:56:25 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/01 15:00:09 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <sstream>

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning (void);
		void error(void);

	public:
		Harl(void);
		~Harl(void);
		void complainfilter (std::string l);
};

#endif
