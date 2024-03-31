/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:25:15 by yhachami          #+#    #+#             */
/*   Updated: 2023/11/11 17:33:17 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

void ShrubberyCreationForm::_execute(Bureaucrat const & executor) const
{
	(void)(executor);
   std::ofstream file;
   file.open(Target + "_shrubbery");
   file << "     \\ i.     / s       /" << std::endl;
   file << "      \\  \\   /         /" << std::endl;
   file << "      .n'   |      a  |_.-._" << std::endl;
   file << "     /  /   /       .-'      `-.      --._" << std::endl;
   file << "    /  /    |     /            \\-.__'       `." << std::endl;
   file << "   |  (     |    |     _        \\   _      .-.  \\" << std::endl;
   file << "   |   `-.-'     |  .-' '-.      | ' `-.  (   )_ |" << std::endl;
   file << "    `-._         \\ (  |    \\     /      \\  `-'  `." << std::endl;
   file << "        `--.      \\ ) \\ \\`-'    /        | .'" << std::endl;
   file << "            \\    .- '-.| `-._.-' \\      /  \\" << std::endl;
   file << "            |   /      \\     .    `._.-'    |" << std::endl;
   file << "            |  / |      |     '            /" << std::endl;
   file << "            | (_/       |      `-._     _.'" << std::endl;
   file << "            \\ //\\      .|           `--'" << std::endl;
   file << "             \\  \\   '\\ \\___/)_          " << std::endl;
   file << "              |   |  ` \\_      \\`  ,        " << std::endl;
   file << "              \\   \\       (\\ .o-`-o    " << std::endl;
   file << "              |    \\__  _______,-'\\`      " << std::endl;
   file << "              \\      ( |  |              " << std::endl;
   file << "               |      \\\\  |               " << std::endl;
   file.close();
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 25, 5)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 25, 5) , Target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : AForm("Shrubbery Creation", 25, 5) , Target(src.Target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		this->Target = rhs.Target;
	}
	return *this;
}
