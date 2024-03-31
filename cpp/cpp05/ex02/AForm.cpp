/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 06:35:17 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/06 08:33:57 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getGrade2Execute())
		throw GradeTooLowException();
	else if (!getSignature())
		throw FormNotSignedException();
	else
		this->_execute(executor);
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > getGrade2Sign())
		throw GradeTooLowException();
	else if (getSignature())
		throw FormAlreadySignedException();
	else
		isSigned = true;
}

const std::string AForm::getName() const 
{
	return (Name);
}

int AForm::getSignature() const
{
	return (isSigned);
}

int AForm::getGrade2Sign() const
{
	return (grade2sign);
}

int AForm::getGrade2Execute() const
{
	return (grade2execute);
}

AForm::AForm(std::string name, int g2sign, int g2execute) : Name(name) , isSigned(false), grade2sign(g2sign), grade2execute(g2execute)
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

AForm::AForm() : Name() , isSigned(false), grade2sign(1), grade2execute(1)
{
}

AForm::AForm( const AForm & o ) : Name(o.Name) , isSigned(false), grade2sign(o.grade2sign), grade2execute(o.grade2execute)
{
}

AForm::~AForm()
{
}

AForm & AForm::operator=( AForm const & o )
{
	(void)(o);
	return *this;
}

std::ostream & operator<<( std::ostream & o, AForm const & i )
{
	if (i.getSignature())
		o << "From " << i.getName() << " is Signed";
	else
		o << "From " << i.getName() << " is not Signed";
	o << " and it Requires " << i.getGrade2Sign() << " to be signed and " << i.getGrade2Execute() << " to be executed";
	return o;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

const char* AForm::FormAlreadySignedException::what() const throw()
{
	return "Form is Already Signed";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is Not Signed";
}
