/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 03:23:34 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/03 11:36:15 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void FragTrap::highFivesGuys(void)
{
   std::cout << "FragTrap " << Name << " is requesting a positive high fives" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &c)
{
   this->Name = c.Name;
   this->HitPoints = c.HitPoints;
   this->EnergyPoints = c.EnergyPoints;
   this->AttackDamage = c.AttackDamage;
   return (*this);
}

FragTrap::FragTrap(FragTrap &copy)
{
   std::cout << "FragTrap copy constructor called" << std::endl;
   *this = copy;
}

FragTrap::FragTrap()
{
   std::cout << "FragTrap Default constructor called" << std::endl;
   Name = "(no name)";   
   HitPoints = 100;
   EnergyPoints = 100;
   AttackDamage = 30;
}

FragTrap::FragTrap(std::string name)
{
   std::cout << "FragTrap constructor called" << std::endl;
   Name = name;   
   HitPoints = 100;
   EnergyPoints = 100;
   AttackDamage = 30;
}

FragTrap::~FragTrap()
{
   std::cout << "FragTrap Destructor called" << std::endl;
}
