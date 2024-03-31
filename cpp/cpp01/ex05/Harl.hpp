/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:21:09 by yhachami          #+#    #+#             */
/*   Updated: 2023/10/24 21:57:20 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl
{
private:
   void debug( void );
   void info( void );
   void warning( void );
   void error( void );

public:
   Harl();
   ~Harl();

   void complain( std::string level );
};

