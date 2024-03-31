/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:31:59 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/24 18:37:32 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string Weapon::getType( void )
{
   return (this->type);
}

void  Weapon::setType(std::string type)
{
   this->type = type;
}

Weapon::Weapon(std::string type)
{
   this->type = type;
}

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}
