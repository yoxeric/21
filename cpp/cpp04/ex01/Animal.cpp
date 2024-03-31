/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:01:26 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/03 18:27:50 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

void Animal::makeSound() const
{
   std::cout << "Fake Animal sound" << std::endl;
}

std::string Animal::getType() const
{
   return (type);
}

Animal &Animal::operator=(Animal &a)
{
   std::cout << "Animal Copy assignment operator called" << std::endl;
   this->type = a.type;
   return (*this);
}

Animal::Animal(Animal &a)
{
   std::cout << "Animal Copy constructor called" << std::endl;
   this->type = a.type;
}

Animal::Animal()
{
   std::cout << "Animal Default constructor called" << std::endl;
   this->type = "Animal";
}

Animal::~Animal()
{
   std::cout << "Animal Destructor called" << std::endl;
}
