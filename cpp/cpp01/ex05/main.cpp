/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:18:46 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/24 21:59:55 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
   Harl harl;

   std::cout << " [ WARNING ] " << std::endl;
   harl.complain("WARNING");
   std::cout << " [ ERROR ] " << std::endl;
   harl.complain("ERROR");
   std::cout << " [ INFO ] " << std::endl;
   harl.complain("INFO");
   std::cout << " [ DEBUG ] " << std::endl;
   harl.complain("DEBUG");
   return 0;
}
