/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:47:58 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/24 18:32:11 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
   Zombie *z;

   z = new Zombie[N];
   for (size_t i = 0; i < N; i++)
   {
      z[i].rename(name);
   }
   return (z);
}
