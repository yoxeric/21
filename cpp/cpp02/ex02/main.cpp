/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:52:25 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/26 19:33:59 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
   Fixed a;
   Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
   
   std::cout << a << std::endl;
   std::cout << ++a << std::endl;
   std::cout << a << std::endl;
   std::cout << a++ << std::endl;
   std::cout << a << std::endl;
   std::cout << b << std::endl;
   std::cout << Fixed::max( a, b ) << std::endl;

   Fixed v1(2), v2(4);
   Fixed v3 = v1.operator*(v2);

   std::cout << v3 << std::endl;

   Fixed c(2147483647);
   Fixed d(5.05f);
   Fixed e(d);
   
   std::cout << c << std::endl;
   std::cout << d << std::endl;
   std::cout << " *  = " << c * d << std::endl;
   std::cout << " /  = " << c / d << std::endl;
   std::cout << " -  = " << c - d << std::endl;
   std::cout << " +  = " << c + d << std::endl;
   std::cout << "/0  = " << e / 0 << std::endl;
   
   std::cout << (c < d) << std::endl;
   std::cout << (c <= d) << std::endl;
   std::cout << (c > d) << std::endl;
   std::cout << (c >= d) << std::endl;
   std::cout << (e == d) << std::endl;
   std::cout << (e != d) << std::endl;

   return 0;
}
