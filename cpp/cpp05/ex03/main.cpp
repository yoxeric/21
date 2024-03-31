/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:57:41 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/15 21:25:27 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
   try
   {
      {
         Intern someRandomIntern;
         AForm* rrf;
         rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
         delete rrf;
         system("leaks Bureaucrat");
      }
      // Bureaucrat a("mol lbanka", 3);
      // Bureaucrat b("mol chkara", 52);
      // Bureaucrat c("mol lgiton", 145);
      // PresidentialPardonForm f1("mol lard");
      // ShrubberyCreationForm f2("mol btata");
      // RobotomyRequestForm f3("mol charika");

      // a.executeForm(f1);
      // a.executeForm(f2);
      // a.executeForm(f3);
      // a.signForm(f1);
      // a.signForm(f2);
      // a.signForm(f3);
      // b.executeForm(f1);
      // b.executeForm(f2);
      // b.executeForm(f3);
      
      // b.incrementGrade();
      // std::cout << b << std::endl;

      // c.signForm(f1);
      // c.signForm(f2);
      // c.signForm(f3);
      // c.executeForm(f1);
      // c.executeForm(f2);
      // c.executeForm(f3);
   }
   catch (std::exception &e)
   {
      std::cout << e.what() << std::endl;
   }
   return 0;
}
