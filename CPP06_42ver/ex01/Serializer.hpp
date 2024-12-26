/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:44:15 by scharuka          #+#    #+#             */
/*   Updated: 2024/12/26 05:08:28 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

struct Data
{
	std::string s1;
	int n;
};

class Serializer
{
public:
	static __intptr_t serialize(Data* ptr);
	static Data* deserialize(__intptr_t raw);

private:
	Serializer();
	Serializer(const Serializer &copy);
	~Serializer();
	Serializer &operator=(const Serializer &copy);
};
