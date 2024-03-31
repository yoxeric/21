/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 06:35:16 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/11 17:25:11 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string Name;
	bool	isSigned;
	const int grade2sign;
	const int grade2execute;

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

	Form();
	Form(std::string Name, int grade2sign, int grade2execute);
	Form(Form const &src);
	~Form();

	Form &operator=(Form const &rhs);

	const std::string getName() const ;
	int getGrade2Sign() const;
	int getGrade2Execute() const;
	int getSignature() const;

	void beSigned(Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif