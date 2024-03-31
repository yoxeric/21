/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:26:34 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/12 10:37:05 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string Target;
	virtual void _execute(Bureaucrat const & executor) const;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string Target);
	RobotomyRequestForm( RobotomyRequestForm const & src );
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=( RobotomyRequestForm const & rhs );

	void execute(Bureaucrat const & executor) const;
};


#endif