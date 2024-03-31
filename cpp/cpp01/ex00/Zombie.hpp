/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:10:39 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/17 17:03:44 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Zombie
{
   private:
      std::string name;
   public:
      Zombie(std::string name);
      ~Zombie();
      
      void announce( void );
      void create( std::string name );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
