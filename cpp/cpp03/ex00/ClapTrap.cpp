/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 02:23:17 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/03 11:31:53 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void ClapTrap::stats()
{
   std::cout << std::endl;
   std::cout << "-----ClapTrap " << Name << " stats: " << std::endl;
   std::cout << " | HitPoints:" <<  HitPoints << std::endl;
   std::cout << " | EnergyPoints:" <<  EnergyPoints << std::endl;
   std::cout << " | AttackDamage:" <<  AttackDamage << std::endl;
   std::cout << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
   if (HitPoints <= 0)
   {
      std::cout << "ClapTrap " << Name << " is Dead" << std::endl;
      return ;
   }
   if (EnergyPoints <= 0)
   {
      std::cout << "ClapTrap " << Name << " has no energy" << std::endl;
      return ;
   }
   std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
   EnergyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
   std::cout << "ClapTrap " << Name << " have been attacked causing " << amount << " points of damage!" << std::endl;
   HitPoints -= amount;
   if (HitPoints <= 0)
      std::cout << "ClapTrap" << Name << " had been slain" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
   if (HitPoints <= 0)
   {
      std::cout << "ClapTrap " << Name << " is Dead" << std::endl;
      return ;
   }
   if (EnergyPoints <= 0)
   {
      std::cout << "ClapTrap " << Name << " has no energy" << std::endl;
      return ;
   }
   std::cout << "ClapTrap " << Name << " repairs itself, it gets " << amount << " hit points back" << std::endl;
   EnergyPoints--;
   HitPoints += amount;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c)
{
   if (&c != this)
   {
      this->Name = c.Name;
      this->HitPoints = c.HitPoints;
      this->EnergyPoints = c.EnergyPoints;
      this->AttackDamage = c.AttackDamage;
   }
   return (*this);
}

ClapTrap::ClapTrap(ClapTrap &copy)
{
   std::cout << "ClapTrap copy constructor called" << std::endl;
   *this = copy;
}

ClapTrap::ClapTrap() : Name("(no name)"), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
   std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
   std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
   std::cout << "ClapTrap Destructor called" << std::endl;
}
