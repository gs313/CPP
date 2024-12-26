/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:44:18 by scharuka          #+#    #+#             */
/*   Updated: 2024/12/26 05:08:07 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{

}
Serializer::~Serializer()
{

}
Serializer::Serializer(const Serializer &copy)
{
	*this = copy;
}
Serializer &Serializer::operator=(const Serializer &copy)
{
	if (this != &copy)
		*this = copy;
	return (*this);
}
__intptr_t Serializer::serialize(Data* ptr)
{
	if (!ptr)
		return (0);
	return (reinterpret_cast<__intptr_t>(ptr));
}
Data* Serializer::deserialize(__intptr_t raw)
{
	if(!raw)
		return (NULL);
	return (reinterpret_cast<Data*>(raw));
}
