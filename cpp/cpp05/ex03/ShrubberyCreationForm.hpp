/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:25:03 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/12 10:37:13 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string Target;
	virtual void _execute(Bureaucrat const & executor) const;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string Target);
	ShrubberyCreationForm( ShrubberyCreationForm const & src );
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=( ShrubberyCreationForm const & rhs );

	void execute(Bureaucrat const & executor) const;
};


#endif