/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:21:11 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/24 21:57:13 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
   std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do! " << std::endl;   
}

void Harl::info( void )
{
   std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;   
}

void Harl::warning( void )
{
   std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;   
}

void Harl::error( void )
{
   std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;   
}

void  Harl::complain( std::string level )
{
   std::string str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
   void (Harl::*arr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
   Harl harl;

   for (size_t i = 0; i < 4; i++)
   {
      if (str[i] == level)
      {
         (harl.*arr[i])();
         break ;
      }
   }
}

Harl::Harl()
{
}

Harl::~Harl()
{
}
