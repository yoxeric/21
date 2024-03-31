/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:31:53 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/24 22:43:59 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void  HumanB::attack()
{
   if (this->weapon && this->weapon->getType().length() > 0)
      std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
   else
      std::cout << this->name << " attack with bare hands" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
   this->weapon = &weapon;
}

HumanB::HumanB(std::string s)
{
   weapon = NULL;
   this->name = s;
}

HumanB::HumanB()
{
}

HumanB::~HumanB()
{
}