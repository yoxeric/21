/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 06:35:17 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/12 10:28:23 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > getGrade2Sign())
		throw GradeTooLowException();
	else if (getSignature())
		throw FormAlreadySignedException();
	else
		isSigned = true;
}

const std::string Form::getName() const 
{
	return (Name);
}

int Form::getSignature() const
{
	return (isSigned);
}

int Form::getGrade2Sign() const
{
	return (grade2sign);
}

int Form::getGrade2Execute() const
{
	return (grade2execute);
}

Form::Form(std::string name, int g2sign, int g2execute) : Name(name) , isSigned(false), grade2sign(g2sign), grade2execute(g2execute)
{
	if (grade2sign > 150)
		throw (GradeTooLowException());
	else if (grade2sign < 1)
		throw (GradeTooHighException());
	if (grade2execute > 150)
		throw (GradeTooLowException());
	else if (grade2execute < 1)
		throw (GradeTooHighException());
}

Form::Form() : Name() , isSigned(false), grade2sign(1), grade2execute(1)
{
}

Form::Form( const Form & o ) : Name(o.Name) , isSigned(false), grade2sign(o.grade2sign), grade2execute(o.grade2execute)
{
}

Form::~Form()
{
}

Form & Form::operator=( Form const & o )
{
	(void)(o);
	return *this;
}

std::ostream & operator<<( std::ostream & o, Form const & i )
{
	if (i.getSignature())
		o << "From " << i.getName() << " is Signed";
	else
		o << "From " << i.getName() << " is not Signed";
	o << " and it Requires " << i.getGrade2Sign() << " to be signed and " << i.getGrade2Execute() << " to be executed";
	return o;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

const char* Form::FormAlreadySignedException::what() const throw()
{
	return "Form is Already Signed";
}
