/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:40:48 by scharuka          #+#    #+#             */
/*   Updated: 2025/06/23 16:48:46 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <stdexcept>
# include <string>
# include <cstdlib>


template <typename T>
class Array
{
	private:
		T* _array;
		unsigned int _size;
	public:
		Array(void) : _array(NULL), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n)
		{
			for (unsigned int i = 0; i < n; i++)
				_array[i] = T();
		}
		Array(const Array& other) : _array(NULL), _size(0)
		{
			*this = other;
		}
		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				delete[] _array;
				_size = other._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = other._array[i];
			}
			return *this;
		}
		~Array(void)
		{
			delete[] _array;
		}
		T& operator[](unsigned int index)
		{
			if (index >= _size)
				throw std::out_of_range("Index out of range");
			return _array[index];
		}
		const T& operator[](unsigned int index) const
		{
			if (index >= _size)
				throw std::out_of_range("Index out of range");
			return _array[index];
		}
		unsigned int size(void) const
		{
			return _size;
		}
};

#endif
