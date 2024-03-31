/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:01:24 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/03 18:41:20 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void Dog::makeSound() const
{
   std::cout << "How 3aw" << std::endl;
}

Dog &Dog::operator=(Dog &d)
{
   std::cout << "Dog Copy assignment operator called" << std::endl;
   this->type = d.type;
   if (this->brain != NULL)
      delete this->brain;
   this->brain = new Brain(*d.brain);
   return (*this);
}

Dog::Dog(Dog &d)
{
   std::cout << "Dog Copy constructor called" << std::endl;
   this->type = d.type;
   this->brain = new Brain(*d.brain);
}

Dog::Dog()
{
   std::cout << "Dog Default constructor called" << std::endl;
   brain = new Brain();
   this->type = "Dog";
}

Dog::~Dog()
{
   std::cout << "Dog Destructor called" << std::endl;
   delete brain;
}
