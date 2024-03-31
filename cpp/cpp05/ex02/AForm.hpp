/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 06:35:16 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/06 08:21:33 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string Name;
	bool	isSigned;
	const int grade2sign;
	const int grade2execute;
	virtual void _execute(Bureaucrat const & executor) const = 0;

public:
	class GradeTooHighException: public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		const char* what() const throw();
	};
	class FormAlreadySignedException: public std::exception
	{
		const char* what() const throw();
	};
	class FormNotSignedException: public std::exception
	{
		const char* what() const throw();
	};

	AForm();
	AForm(std::string Name, int grade2sign, int grade2execute);
	AForm(AForm const &src);
	virtual ~AForm();

	AForm &operator=(AForm const &rhs);

	const std::string getName() const;
	int getGrade2Sign() const;
	int getGrade2Execute() const;
	int getSignature() const;

	void beSigned(Bureaucrat &b);

	void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &o, AForm const &i);

#endif