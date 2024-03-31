/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:03:04 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/03 10:41:36 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCAVTRAP_HPP_
#define _SCAVTRAP_HPP_

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
   ScavTrap();
   ScavTrap(ScavTrap &c);
   ScavTrap(std::string name);
   ~ScavTrap();

   ScavTrap &operator=(const ScavTrap &c);
   
   void attack(const std::string& target);
   void guardGate();
};

#endif
