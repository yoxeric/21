/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:58:56 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/12 10:24:10 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << Name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << Name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << Name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << Name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

const std::string Bureaucrat::getName() const
{
	return (Name);
}

int Bureaucrat::getGrade() const
{
	return (Grade);
}

void Bureaucrat::incrementGrade()
{
	if (Grade <= 1)
		throw GradeTooHighException();
	Grade--;
}

void Bureaucrat::decrementGrade()
{
	if (Grade >= 150)
		throw GradeTooLowException();
	Grade++;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &b)
{
	if ( this != &b )
		Grade = b.getGrade();
	return (*this);
}

Bureaucrat::Bureaucrat(std::string n, int g) : Name(n) , Grade(g)
{
	if (Grade > 150)
		throw GradeTooLowException();
	if (Grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : Name(b.getName()) , Grade(b.getGrade())
{}

Bureaucrat::Bureaucrat() : Name() , Grade(150)
{}

Bureaucrat::~Bureaucrat()
{}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat Grade Too High Exception";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat Grade Too Low Exception";
}