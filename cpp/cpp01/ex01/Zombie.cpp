/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:10:22 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/17 18:20:03 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce( void )
{
   std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::rename(std::string name)
{
   this->name = name;
}

Zombie::Zombie()
{
   std::cout << this->name << " is back from the dead" << std::endl;
}

Zombie::Zombie(std::string name)
{
   this->name = name;
}

Zombie::~Zombie()
{
   std::cout << this->name << " Destroyed" << std::endl;
}