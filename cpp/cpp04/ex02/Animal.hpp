/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:58:15 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/29 20:54:35 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ANIMAL_HPP_
#define _ANIMAL_HPP_

#include <iostream>

class Animal
{
protected:
   std::string type;
public:
   Animal();
   Animal(Animal &a);
   virtual ~Animal();

   Animal &operator= (Animal &a);

   virtual std::string getType() const;
   virtual void makeSound() const = 0;
};

#endif
