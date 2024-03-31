/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:43:36 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/24 18:06:52 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char const **av)
{
   std::size_t		i = 0;
	std::ifstream	file;
	std::ofstream	file2;
	std::string		line;
	std::string		text;
	std::string		name;
   
   if (ac == 4)
   {
      file.open(av[1]);
		if (!file || file.peek() == std::string::npos)
		{
			std::cout << "File Error" << std::endl;
		}
      while (getline(file, line))
      {
			i = line.find(av[2]);
			while (i != std::string::npos)
			{
				line.erase(i, strlen(av[2]));
				line.insert(i, av[3]);
				i = line.find(av[2]);
			}
         text.append(line);
			text.append("\n");
      }
		file.close();
		name = av[1];
		name += ".replace";
      file2.open(name);
		file2 << text << std::endl;
		file2.close();
   }
	else
		std::cout << "./sed <file> <word1> <word2>" << std::endl;
   return 0;
}
