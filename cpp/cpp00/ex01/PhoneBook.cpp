/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 00:16:26 by yhachami          #+#    #+#             */
/*   Updated: 2023/09/19 19:12:58 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	is_numbre(std::string s)
{
	for (size_t i = 0; s[i]; i++)
		if (!isdigit(s[i]))
			return (0);
	return (1);	
}

std::string	get_input(std::string msg)
{
	std::string input;

	while (input.length() == 0)
	{
		std::cout << msg;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
	}
	return (input);
}

void	PhoneBook::show(int size)
{
	int			i;
	Contact		contact;

	std::cout << "*-------------------------------------------*" << std::endl;
	std::cout << "|    index |first name| last name|  nickname|" << std::endl;
	std::cout << "*-------------------------------------------*" << std::endl;
	for (i = 1; i <= size; i++)
	{
		contact = this->get_contact(i - 1);
		contact.bookprint(i);
	}
}

void PhoneBook::search(int size)
{
	Contact		contact;
	std::string	input;
	int			i;

	this->show(size);
	if (size > 0)
	{
		while (1)
		{
			input = get_input("contact index -> ");
			if (is_numbre(input) == 1)
				i = stoi(input);
			else
			{
				std::cout << "invalid input" << std::endl;
				return ;
			}
			if (i > 0 && i <= 8 && i <= size)
			{
				contact = this->get_contact(i - 1);
				contact.print();
				return ;
			}
			else
			{
				std::cout << "invalid input" << std::endl;
				return ;
			}
		}
	}
	else
	{
		std::cout << "|                   EMPTY                   |" << std::endl;
		std::cout << "*-------------------------------------------*" << std::endl;
	}
	return ;
}


void PhoneBook::add_contact(int x)
{
	std::string input;
	Contact contact;

	contact.set_first_name(get_input("first name: "));
	contact.set_last_name(get_input("last name: "));
	contact.set_nickname(get_input("nickname: "));
	contact.set_phone_number(get_input("phone number: "));
	contact.set_darkest_secret(get_input("darkest secret: "));
	this->set_contact(contact, x - 1);
}

PhoneBook::PhoneBook()
{
	// std::cout << "Phonebook Constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	// std::cout << "Phonebook Destructor called" << std::endl;
}


void PhoneBook::set_contact(Contact contact, int i)
{
	this->contact[i] = contact;
}

Contact PhoneBook::get_contact(int i)
{
	return (contact[i]);
}
