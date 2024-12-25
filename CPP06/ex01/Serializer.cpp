/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:44:18 by scharuka          #+#    #+#             */
/*   Updated: 2024/12/25 22:07:52 by scharuka         ###   ########.fr       */
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
uintptr_t Serializer::serialize(Data* ptr)
{
	if (!ptr)
		return (0);
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data* Serializer::deserialize(uintptr_t raw)
{
	if(!raw)
		return (NULL);
	return (reinterpret_cast<Data*>(raw));
}