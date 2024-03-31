/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 02:22:44 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/03 11:25:14 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int   main()
{
   ClapTrap c("mr. strap");

   c.stats();

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