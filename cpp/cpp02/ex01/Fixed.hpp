/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:56:08 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/26 17:54:22 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

   int getRawBits( void ) const;
   void setRawBits( int const raw );

   float toFloat( void ) const;
   int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);
