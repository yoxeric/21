/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:58:59 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/12 10:36:24 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string Name;
	int	Grade;

public:
	class GradeTooHighException: public std::exception
	{
		const char* what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		const char* what() const throw();
	};

	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &b);

	const std::string getName() const ;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(AForm &form);

	void executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif