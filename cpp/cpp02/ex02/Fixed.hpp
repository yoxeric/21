/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:56:08 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/26 17:56:16 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_
#define _FIXED_HPP_

#include <iostream>
#include <cmath>

class Fixed
{
private:
   int   numbre;
   static const int fraction;

public:
   Fixed();
   Fixed(const int nb);
   Fixed(const float nb);
   Fixed(const Fixed& f);
   ~Fixed();

   Fixed& operator=(const Fixed&);

   Fixed operator+(const Fixed &b);
   Fixed operator-(const Fixed &b);
   Fixed operator*(const Fixed &b);
   Fixed operator/(const Fixed &b);

   Fixed &operator++();
   Fixed operator++(int);
   Fixed &operator--();
   Fixed operator--(int);

   bool operator==(const Fixed& b);
   bool operator!=(const Fixed& b);
   bool operator< (const Fixed& b);
   bool operator> (const Fixed& b);
   bool operator<=(const Fixed& b);
   bool operator>=(const Fixed& b);

   int getRawBits( void ) const;
   void setRawBits( int const raw );

   float toFloat( void ) const;
   int toInt( void ) const;

   static Fixed &max(Fixed &a, Fixed &b);
   static const Fixed &max(const Fixed &a, const Fixed &b);
   static Fixed &min(Fixed &a, Fixed &b);
   static const Fixed &min(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif