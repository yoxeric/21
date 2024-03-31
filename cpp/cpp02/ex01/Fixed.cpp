/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:56:01 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/26 18:30:46 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fraction = 8;

Fixed::Fixed(const int nb)
{
   std::cout << "Int constructor called" << std::endl;
   this->numbre = nb << fraction;
}

Fixed::Fixed(const float nb)
{
   std::cout << "Float constructor called" << std::endl;
   this->numbre = roundf(nb * (1 << fraction));
}

Fixed::Fixed(const Fixed &f)
{
   std::cout << "Copy constructor called" << std::endl;
   this->numbre = f.getRawBits();
   *this = f;
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

float Fixed::toFloat( void ) const
{
   return (roundf(numbre) / (1 << fraction));
}

int Fixed::toInt( void ) const
{
   return (this->numbre >> fraction);
}

int Fixed::getRawBits( void ) const
{
   return (this->numbre);
}

void Fixed::setRawBits( int const raw )
{
   this->numbre = raw;
}

Fixed& Fixed::operator=(const Fixed& f)
{
   std::cout << "Copy assignment operator called" << std::endl;
   this->numbre = f.getRawBits();
   return (*this);
}

std::ostream& operator<<(std::ostream& os, Fixed const &f)
{
   // std::cout << "Overload operator called" << std::endl;
   return (os << f.toFloat());
}

