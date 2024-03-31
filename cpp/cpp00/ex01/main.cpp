/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:46:59 by yhachami          #+#    #+#             */
/*   Updated: 2023/09/18 01:47:12 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	int			x = 1;
	int			size = 0;
	std::string	input;
	PhoneBook	phonebook;

	while (x)
	{
		std::cout << "command -> ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
		if (input.compare("ADD") == 0)
		{
			phonebook.add_contact(x);
			x++;
			if (x == 9)
				x = 1;
			if (size < 8)
				size++;
		}
		else if (input.compare("SEARCH") == 0)
			phonebook.search(size);
		else if (input.compare("EXIT") == 0)
			x = 0;
	}
	return 0;
}
