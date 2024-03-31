/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:10:39 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/24 00:59:35 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Zombie
{
   private:
      std::string name;
   public:
      Zombie();
      Zombie(std::string name);
      ~Zombie();
      
      void announce( void );
      void rename( std::string name );
};

Zombie* zombieHorde( int N, std::string name );
