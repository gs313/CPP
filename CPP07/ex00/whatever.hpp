/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:57:27 by scharuka          #+#    #+#             */
/*   Updated: 2025/05/11 11:32:20 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename P>
const P& min(const P& a, const P&b)
{
	return (a < b ? a : b);
}
template <typename G>
const G& max (const G& a,const G& b)
{
	return (a > b ? a :b);
}
#endif
