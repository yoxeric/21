/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:01:28 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/03 18:41:21 by yhachami         ###   ########.fr       */
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
   if (this->brain != NULL)
      delete this->brain;
   this->brain = new Brain(*c.brain);
   return (*this);
}

Cat::Cat(Cat &c)
{
   std::cout << "Cat Copy constructor called" << std::endl;
   this->type = c.type;
   this->brain = new Brain(*c.brain);
}

Cat::Cat()
{
   std::cout << "Cat Default constructor called" << std::endl;
   brain = new Brain();
   this->type = "Cat";
}

Cat::~Cat()
{
   std::cout << "Cat Destructor called" << std::endl;
   delete brain;
}
