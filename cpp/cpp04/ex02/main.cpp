/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:58:08 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/03 18:55:23 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
   const Animal* j = new Dog();
   const Animal* i = new Cat();

   std::cout << "----- Start Destructor" << std::endl;

   delete j;
   delete i;
   
   // ...

   // Animal test;    //     < --------------------------- this is an Error

   // ...

   std::cout << "----- Test Dog Brain" << std::endl;

   Dog basic;
   {
      Dog tmp = basic;
   }

   std::cout << std::endl;
   system("Leaks Animal");


   return 0;
}
