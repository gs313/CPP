/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:40:58 by scharuka          #+#    #+#             */
/*   Updated: 2025/06/23 16:27:54 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

template <typename T>
void incrementElement(T& element) {
    element += 1;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original int array: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;

    iter(intArray, intArrayLength, incrementElement<int>);

    std::cout << "After increment: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;

    const double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Const double array: ";
    iter(doubleArray, doubleArrayLength, printElement<double>);
    std::cout << std::endl;


    // iter(doubleArray, doubleArrayLength, incrementElement<double>);

    return 0;
}
