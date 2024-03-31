/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:10:04 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/24 18:24:39 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
   Zombie *z;
   
   z = newZombie( "dead chink" );
   randomChump( "dead niger" );
   delete z;
   
   return 0;
}
