/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:40:54 by scharuka          #+#    #+#             */
/*   Updated: 2025/05/11 11:48:18 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <string>

template <typename T>
void iter(T* array, size_t length, void (*func)(T&))
{
	if (array == nullptr || func == nullptr)
	{
		return;
	}
	for (size_t i = 0; i < length; ++i)
	{
		func(array[i]);
	}
}

#endif
