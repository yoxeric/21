/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:52:25 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/20 09:44:39 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
   Fixed a;
   Fixed b( a );
   Fixed c;

   c = b;
   std::cout << a.getRawBits() << std::endl;
   std::cout << b.getRawBits() << std::endl;
   std::cout << c.getRawBits() << std::endl;
   return 0;
}