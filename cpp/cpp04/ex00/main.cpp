/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:58:08 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/03 18:47:16 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
   const Animal* meta = new Animal();

   const Animal* j = new Dog();
   const Animal* i = new Cat();

   std::cout << j->getType() << " " << std::endl;
   std::cout << i->getType() << " " << std::endl;
   i->makeSound(); //will output the cat sound!
   j->makeSound();
   meta->makeSound();

   delete i;
   delete j;

   delete meta;
   
   // const WrongAnimal* q = new WrongAnimal();

   // const WrongAnimal* w = new WrongCat();
   // const WrongCat* x = new WrongCat();

   // std::cout << w->getType() << " " << std::endl;
   // w->makeSound();
   // x->makeSound();
   // q->makeSound();

   // delete w;
   // delete x;

   // delete q;
   
   return 0;
}
