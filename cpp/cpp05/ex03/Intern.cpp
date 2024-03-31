/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:02:39 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/12 10:35:09 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm *make1From(std::string a)
{
	return (new PresidentialPardonForm(a));
}

AForm *make2From(std::string a)
{
	return (new ShrubberyCreationForm(a));
}

AForm *make3From(std::string a)
{
	return (new RobotomyRequestForm(a));
}

Intern::Intern()
{
}

Intern::Intern(const Intern &src) 
{
	*this = src;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const &rhs)
{
	(void)(rhs);
	return *this;
}


AForm *Intern::makeForm(std::string a, std::string b)
{
	std::string ok[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm *(*array[])(std::string a) = {&make1From, &make2From, &make3From};

	for (size_t i = 0; i < 3; i++)
	{
		if (a == ok[i])
		{
			return (array[i](b));
		}
	}
	std::cout << "Error making Form" << std::endl;
	return (NULL);
}
