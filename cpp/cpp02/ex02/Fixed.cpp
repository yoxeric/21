/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:56:01 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/06 06:32:57 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fraction = 8;

// Constructors

Fixed::Fixed(const int nb)
{
   this->numbre = nb << fraction;
}

Fixed::Fixed(const float nb)
{
   this->numbre = roundf(nb * (1 << fraction));
}

Fixed::Fixed(const Fixed &f)
{
   this->numbre = f.getRawBits();
   *this = f;
}

Fixed::Fixed()
{
   this->numbre = 0;
}

Fixed::~Fixed()
{
}

// Fixed

float Fixed::toFloat( void ) const
{
   return (roundf(this->numbre) / (1 << fraction));
}

int Fixed::toInt( void ) const
{
   return (this->numbre / (1 << fraction));
}

int Fixed::getRawBits( void ) const
{
   return (this->numbre);
}

void Fixed::setRawBits( int const raw )
{
   this->numbre = raw;
}

// Operators

Fixed& Fixed::operator=(const Fixed& f)
{
   this->numbre = f.getRawBits();
   return (*this);
}

std::ostream& operator<<(std::ostream& os, Fixed const &f)
{
   return (os << f.toFloat());
}

Fixed &Fixed::operator++()
{
   this->numbre++;
   return (*this);
}

Fixed Fixed::operator++(int)
{
   Fixed old = *this;
   operator++();
   return (old);
}

Fixed &Fixed::operator--()
{
   this->numbre--;
   return (*this);
}

Fixed Fixed::operator--(int)
{
   Fixed old = *this;
   operator--();
   return (old);
}

Fixed Fixed::operator+(const Fixed& b)
{
   Fixed f(getRawBits() + b.getRawBits());
   return (f);
}

Fixed Fixed::operator-(const Fixed& b)
{
   Fixed f(getRawBits() - b.getRawBits());
   return (f);
}

Fixed Fixed::operator*(const Fixed& b)
{
   Fixed f(getRawBits() * b.getRawBits());
   return (f);
}

Fixed Fixed::operator/(const Fixed& b)
{
   Fixed f(getRawBits() / b.getRawBits());
   return (f);
}

bool Fixed::operator==(const Fixed& b){ return (getRawBits() == b.getRawBits()); }
bool Fixed::operator!=(const Fixed& b){ return (getRawBits() != b.getRawBits()); }
bool Fixed::operator<(const Fixed& b){ return (getRawBits() <  b.getRawBits()); }
bool Fixed::operator>(const Fixed& b){ return (getRawBits() >  b.getRawBits()); }
bool Fixed::operator<=(const Fixed& b){ return (getRawBits() <= b.getRawBits()); }
bool Fixed::operator>=(const Fixed& b){ return (getRawBits() >= b.getRawBits()); }

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
   if (a.getRawBits() > b.getRawBits())
      return (a);
   else
      return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
   if (a.getRawBits() > b.getRawBits())
      return (a);
   else
      return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
   if (a.getRawBits() < b.getRawBits())
      return (a);
   else
      return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
   if (a.getRawBits() < b.getRawBits())
      return (a);
   else
      return (b);
}

