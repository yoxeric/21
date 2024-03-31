/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:52:53 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/29 11:35:13 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WRONGANIMAL_HPP_
#define _WRONGANIMAL_HPP_

#include <iostream>

class WrongAnimal
{
protected:
   std::string type;
public:
   WrongAnimal();
   WrongAnimal(WrongAnimal &w);
   ~WrongAnimal();

   WrongAnimal &operator=(WrongAnimal &w);

   std::string getType() const;
   void makeSound() const;
};

#endif
