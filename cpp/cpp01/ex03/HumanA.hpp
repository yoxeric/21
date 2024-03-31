/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:31:50 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/24 22:24:52 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
   std::string name;
   Weapon *weapon;
public:
   HumanA();
   HumanA(std::string s, Weapon &w);
   ~HumanA();

   void attack();
   void setWeapon(Weapon &W);
};
