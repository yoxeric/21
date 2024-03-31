/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:11:09 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/24 18:09:10 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
   std::string s = "HI THIS IS BRAIN";
   std::string *s_ptr = &s;
   std::string &s_ref = s;

   std::cout << "The memory address of string    : " << &s << std::endl;
   std::cout << "The memory address of pointer   : " << s_ptr << std::endl;
   std::cout << "The memory address of reference : "  << &s_ref << std::endl;

   std::cout << "The value of string     : " << s << std::endl;
   std::cout << "The value of pointer    : " << *s_ptr << std::endl;
   std::cout << "The value of reference  : "  << s_ref << std::endl;

   return 0;
}
