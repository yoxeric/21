/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 02:23:26 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/03 10:42:21 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CLAPTRAP_HPP_
#define _CLAPTRAP_HPP_

#include <iostream>

class ClapTrap
{
private:
   std::string Name;
   int   HitPoints;
   int   EnergyPoints;
   int   AttackDamage;

public:
   ClapTrap();
   ClapTrap(ClapTrap &c);
   ClapTrap(std::string name);
   ~ClapTrap();

   ClapTrap &operator=(const ClapTrap &c);

   void attack(const std::string& target);
   void takeDamage(unsigned int amount);
   void beRepaired(unsigned int amount);

   void stats();
};

#endif
