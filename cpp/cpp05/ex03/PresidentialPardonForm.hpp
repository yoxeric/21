/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:27:06 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/12 10:37:32 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string Target;
	virtual void _execute(Bureaucrat const & executor) const;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string Target);
	PresidentialPardonForm( PresidentialPardonForm const & src );
	~PresidentialPardonForm();

	PresidentialPardonForm & operator=( PresidentialPardonForm const & rhs );

	void execute(Bureaucrat const & executor) const;
};

#endif