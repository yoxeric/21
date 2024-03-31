/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:56:08 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/26 15:18:21 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
private:
   int   numbre;
   static const int fraction;

public:
   Fixed();
   Fixed(Fixed& f);
   ~Fixed();

   Fixed& operator=(Fixed&);

   int getRawBits( void ) const;
   void setRawBits( int const raw );
};

