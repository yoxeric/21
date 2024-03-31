/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:01:28 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/03 18:42:52 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

void WrongCat::makeSound() const
{
   std::cout << "fake Miaow Miaow" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat &w)
{
   std::cout << "WrongCat Copy assignment operator called" << std::endl;
   this->type = w.type;
   return (*this);
}

WrongCat::WrongCat(WrongCat &w)
{
   std::cout << "WrongCat Copy constructor called" << std::endl;
   this->type = w.type;
}

WrongCat::WrongCat()
{
   std::cout << "WrongCat Default constructor called" << std::endl;
   type = "Wrong Cat";
}

WrongCat::~WrongCat()
{
   std::cout << "WrongCat Destructor called" << std::endl;
}
