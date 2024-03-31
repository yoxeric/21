/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:58:37 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/29 12:56:54 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CAT_HPP_
#define _CAT_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
   Brain *brain;
public:
   Cat();
   Cat(Cat &c);
   ~Cat();

   Cat &operator=(Cat &c);

   void makeSound() const;
};

#endif
