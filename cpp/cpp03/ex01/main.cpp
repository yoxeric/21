/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 02:22:44 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/01 10:20:40 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int   main()
{
   ScavTrap c("mr. strap");

   c.guardGate();
   
   c.attack("you");
   std::cout << "you hit back" << std::endl;
   c.takeDamage(5);

   c.stats();

   c.beRepaired(2);
   c.attack("you");
   
   c.stats();

   std::cout << "you hit back even harder" << std::endl;
   c.takeDamage(10);
   
   c.stats();

   c.beRepaired(2);
   c.attack("you");
}