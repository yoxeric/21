/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:01:28 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/29 12:15:39 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void Cat::makeSound() const
{
   std::cout << "Miaow Miaow" << std::endl;
}

Cat &Cat::operator=(Cat &c)
{
   std::cout << "Cat Copy assignment operator called" << std::endl;
   this->type = c.type;
   return (*this);
}

Cat::Cat(Cat &c)
{
   std::cout << "Cat Copy constructor called" << std::endl;
   this->type = c.type;
}

Cat::Cat()
{
   std::cout << "Cat Default constructor called" << std::endl;
   this->type = "Cat";
}

Cat::~Cat()
{
   std::cout << "Cat Destructor called" << std::endl;
}
