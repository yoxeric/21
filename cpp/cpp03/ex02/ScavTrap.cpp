/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:04:02 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/03 11:28:25 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void ScavTrap::guardGate()
{
   std::cout << "ScavTrap " << Name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
   if (HitPoints <= 0)
   {
      std::cout << "ScavTrap " << Name << " is Dead" << std::endl;
      return ;
   }
   if (EnergyPoints < 0)
   {
      std::cout << "ScavTrap " << Name << " has no energy" << std::endl;
      return ;
   }
   std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
   EnergyPoints--;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &c)
{
   this->Name = c.Name;
   this->HitPoints = c.HitPoints;
   this->EnergyPoints = c.EnergyPoints;
   this->AttackDamage = c.AttackDamage;
   return (*this);
}

ScavTrap::ScavTrap(ScavTrap &copy)
{
   std::cout << "ScavTrap copy constructor called" << std::endl;
   *this = copy;
}

ScavTrap::ScavTrap()
{
   std::cout << "ScavTrap Default constructor called" << std::endl;
   Name = "(no name)";
   HitPoints = 100;
   EnergyPoints = 50;
   AttackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
   std::cout << "ScavTrap constructor called" << std::endl;
   Name = name;
   HitPoints = 100;
   EnergyPoints = 50;
   AttackDamage = 20;
}

ScavTrap::~ScavTrap()
{
   std::cout << "ScavTrap Destructor called" << std::endl;
}
