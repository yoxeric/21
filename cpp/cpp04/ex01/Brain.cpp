/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:06:25 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/03 18:32:05 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain &Brain::operator=(Brain &c)
{
   std::cout << "Brain Copy assignment operator called" << std::endl;
   for (size_t i = 0; i < 100; i++)
      ideas[i] = c.ideas[i];
   return (*this);
}

Brain::Brain(Brain &c)
{
   std::cout << "Brain Copy constructor called" << std::endl;
   for (size_t i = 0; i < 100; i++)
      ideas[i] = c.ideas[i];
}

Brain::Brain()
{
   std::cout << "Brain Constructor called" << std::endl;
}

Brain::~Brain()
{
   std::cout << "Brain Destructor called" << std::endl;
}
