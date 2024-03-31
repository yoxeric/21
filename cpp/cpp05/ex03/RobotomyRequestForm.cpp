/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:26:44 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/12 10:36:42 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

void RobotomyRequestForm::_execute(Bureaucrat const & executor) const
{
	(void)(executor);
	srand(time(0)); 
	std::cout << "[ drilling noises... ]" << std::endl;
	if (rand() % 2)
		std::cout << this->Target << " has been robotomized successfully" << std::endl;
	else
		std::cout <<  "robotomy failed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45) , Target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : AForm("Shrubbery Creation", 25, 5) , Target(src.Target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		this->Target = rhs.Target;
	}
	return *this;
}
