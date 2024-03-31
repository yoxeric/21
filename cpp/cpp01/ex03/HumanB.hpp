/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:31:55 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/19 15:38:43 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
   std::string name;
   Weapon *weapon;
public:
   HumanB();
   HumanB(std::string s);
   ~HumanB();

   void attack();
   void setWeapon(Weapon &W);
};
