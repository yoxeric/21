/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 03:23:32 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/03 10:40:19 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRAGTRAP_HPP_
#define _FRAGTRAP_HPP_

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
   FragTrap();
   FragTrap(FragTrap &c);
   FragTrap(std::string name);
   ~FragTrap();

   FragTrap &operator=(const FragTrap &c);

   void highFivesGuys(void);
};

#endif
