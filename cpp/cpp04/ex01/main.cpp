/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:58:08 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/03 18:55:33 by yhachami         ###   ########.fr       */
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

   std::cout << "----- Make 100 Animals" << std::endl;

   Animal* a[100];

   for (size_t i = 0; i < 50; i++)
   {
      a[i] = new Dog();
   }
   for (size_t i = 50; i < 100; i++)
   {
      a[i] = new Cat();
   }

   std::cout << "----- Start DeStructors" << std::endl;
   
   for (size_t i = 0; i < 100; i++)
   {
      delete a[i];
   }


   std::cout << "----- Test Dog Brain" << std::endl;

   Dog basic;
   {
      Dog tmp = basic;
   }

   std::cout << std::endl;
   system("Leaks Animal");

   // ...

   return 0;
}
