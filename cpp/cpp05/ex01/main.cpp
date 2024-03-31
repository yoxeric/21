/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:57:41 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/06 08:09:47 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
   std::cout << "-----   increment test" << std::endl;
   
   try
   {
      Bureaucrat a("mol lbanka", 3);
      Bureaucrat b("mol chkara", 52);
      Form f("Tax", 50, 100);

      std::cout << f << std::endl;
      b.signForm(f);
      a.signForm(f);
      std::cout << b << std::endl;
      b.incrementGrade();
      std::cout << b << std::endl;
      b.incrementGrade();
      std::cout << b << std::endl;
      b.incrementGrade();
      std::cout << b << std::endl;
      b.signForm(f);
   }
   catch (std::exception &e)
   {
      std::cout << e.what() << std::endl;
   }

   std::cout << "-----   copy test" << std::endl;
      
   try
   {
      Bureaucrat a;
      Bureaucrat b("mol chkara", 3);

      std::cout << a << std::endl;
      std::cout << b << std::endl;
      a = b;
      std::cout << a << std::endl;
   }
   catch (std::exception &e)
   {
      std::cout << e.what() << std::endl;
   }
   
   std::cout << "-----   low grade test" << std::endl;
   
   try
   {
      Bureaucrat c("mol charika", 200);

      std::cout << c << std::endl;
   }
   catch (std::exception &e)
   {
      std::cout << e.what() << std::endl;
   }

   std::cout << "-----   hight grade test" << std::endl;
   
   try
   {
      Bureaucrat d("mol lard", -1);

      std::cout << d << std::endl;
   }
   catch (std::exception &e)
   {
      std::cout << e.what() << std::endl;
   }
   return 0;
}
