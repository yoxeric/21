/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:59:43 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/29 17:32:40 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DOG_HPP_
#define _DOG_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
   Brain *brain;
public:
   Dog();
   Dog(Dog &d);
   ~Dog();

   Dog &operator=(Dog &d);

   void makeSound() const;
};

#endif
