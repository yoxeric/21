/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:32:02 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/17 22:52:44 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Weapon
{  
private:
   std::string type;
public:
   Weapon();
   Weapon(std::string type);
   ~Weapon();

   std::string getType();
   void  setType(std::string);
};
