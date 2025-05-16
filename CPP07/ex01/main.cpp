/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:40:58 by scharuka          #+#    #+#             */
/*   Updated: 2025/05/16 15:52:39 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void ) {
	int arr[] = { 1, 2, 3, 4, 5 };
	std::string strArr[] = { "Hello", "World", "!" };

	iter(arr, 5, [](int& n) { n *= 2; });
	iter(strArr, 3, [](std::string& str) { str += "!"; });

	for (int i = 0; i < 5; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	for (int i = 0; i < 3; ++i)
		std::cout << strArr[i] << " ";
	std::cout << std::endl;

	return 0;
	}