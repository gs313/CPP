/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 23:34:41 by scharuka          #+#    #+#             */
/*   Updated: 2024/07/28 15:35:20 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

int main (int argc, char **argv)
{
	if ( argc < 2 )
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for(int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]!='\0';j++)
				std::cout << (char)std::toupper(argv[i][j]);
			std::cout << " ";
		}
		std::cout << std::endl;

	}
}
