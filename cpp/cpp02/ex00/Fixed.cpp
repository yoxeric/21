/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:56:01 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/26 16:44:18 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fraction = 8;

int Fixed::getRawBits( void ) const
{
   std::cout << "getRawBits member function called" << std::endl;
   return (numbre);
}

void Fixed::setRawBits( int const raw )
{
   this->numbre = raw;
}

Fixed& Fixed::operator=(Fixed& f)
{
   std::cout << "Copy assignment operator called" << std::endl;
   this->numbre = f.getRawBits();
   return (*this);
}

Fixed::Fixed(Fixed &f)
{
   std::cout << "Copy constructor called" << std::endl;
   this->numbre = f.getRawBits();
}

Fixed::Fixed()
{
   std::cout << "Default constructor called" << std::endl;
   this->numbre = 0;
}

Fixed::~Fixed()
{
   std::cout << "Destructor called" << std::endl;
}
