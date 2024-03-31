/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 00:14:47 by yhachami          #+#    #+#             */
/*   Updated: 2023/09/18 01:46:54 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string strtrim(std::string s)
{
	if (s.length() > 10)
	{
		s = s.substr(0, 10);
		s[9] = '.';
	}
	return (s);
}

void Contact::print()
{
	std::cout << "first name: " << this->get_first_name() << std::endl;
	std::cout << "last name: " << this->get_last_name() << std::endl;
	std::cout << "nickname: " << this->get_nickname() << std::endl;
	std::cout << "phone number: " << this->get_phone_number() << std::endl;
	std::cout << "darkest secret: " << this->get_darkest_secret() << std::endl;
}

void Contact::bookprint(int i)
{
	std::cout << "|" << std::setw(10) << i << "|";
	std::cout << std::setw(10) << strtrim(this->get_first_name()) << "|";
	std::cout << std::setw(10) << strtrim(this->get_last_name()) << "|";
	std::cout << std::setw(10) << strtrim(this->get_nickname()) << "|" << std::endl;
	std::cout << "*-------------------------------------------*" << std::endl;
}


Contact::Contact()
{
	// std::cout << "Contact Constructor called" << std::endl;
}

Contact::~Contact()
{
	// std::cout << "Contact Destructor called" << std::endl;
}

void Contact::set_first_name(std::string name)
{
	this->first_name = name;
}

void Contact::set_last_name(std::string name)
{
	this->last_name = name;
}

void Contact::set_nickname(std::string name)
{
	this->nickname = name;
}

void Contact::set_phone_number(std::string name)
{
	this->phone_number = name;
}

void Contact::set_darkest_secret(std::string name)
{
	this->darkest_secret = name;
}

std::string Contact::get_first_name()
{
	return (first_name);
}

std::string Contact::get_last_name()
{
	return (last_name);
}

std::string Contact::get_nickname()
{
	return (nickname);
}

std::string Contact::get_phone_number()
{
	return (phone_number);
}

std::string Contact::get_darkest_secret()
{
	return (darkest_secret);
}
