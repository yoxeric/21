/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:31:48 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/24 22:24:50 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void  HumanA::attack()
{
   std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanA::setWeapon(Weapon &weapon)
{
   this->weapon = &weapon;
}

HumanA::HumanA(std::string s, Weapon &w)
{
   this->name = s;
   this->weapon = &w;
}

HumanA::HumanA()
{
}

HumanA::~HumanA()
{
}