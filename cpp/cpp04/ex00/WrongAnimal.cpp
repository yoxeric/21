/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:53:19 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/03 18:34:03 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

void WrongAnimal::makeSound() const
{
   std::cout << "Fake sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
   return (type);
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &w)
{
   std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
   this->type = w.type;
   return (*this);
}

WrongAnimal::WrongAnimal(WrongAnimal &w)
{
   std::cout << "WrongAnimal Copy constructor called" << std::endl;
   this->type = w.type;
}

WrongAnimal::WrongAnimal()
{
   std::cout << "WrongAnimal Default constructor called" << std::endl;
   this->type = "Animal";
}

WrongAnimal::~WrongAnimal()
{
   std::cout << "WrongAnimal Destructor called" << std::endl;
}
