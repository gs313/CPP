/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:36:12 by scharuka          #+#    #+#             */
/*   Updated: 2024/07/30 21:04:13 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define ERRNARG "Error: Wrong number of input (there should be a filename, string s1 and string s1)"
#define ERROPNF "Error: Cannot open file "
#define ERRCTOP "Error: Cannot open file "

void replaces1s2 (std::ofstream &fo, std::string s1, std::string s2, std::string target)
{
size_t pos;
size_t toSkip;
	pos = target.find(s1);

if(pos == std::string::npos)
{
	fo << target;
	return;
}
else
{
	fo << target.substr(0,pos);
	fo << s2;
	toSkip = pos + s1.length();
	replaces1s2(fo,s1,s2,target.substr(toSkip));
}
}

int main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << BOLDRED <<ERRNARG << RESET <<std::endl;
		return 1;
	}
	std::ifstream	inf(argv[1]);
	if (!inf.good())
	{
		std::cout << BOLDRED <<ERROPNF << argv[1] << RESET <<std::endl;
		return 1;
	}
	std::string opfn = ((std::string)argv[1] + ".replace");
	std::ofstream	opf(opfn.c_str(), std::ofstream::out);
	if (!opf.good())
	{
		std::cout << BOLDRED <<ERRCTOP << argv[1] << ".replace" << RESET <<std::endl;
		return 1;
	}

	std::string	line;
	while(std::getline(inf,line))
	{
		replaces1s2(opf, argv[2], argv[3], line + "\n");
	}

	inf.close();
	opf.close();
	return (0);
}
