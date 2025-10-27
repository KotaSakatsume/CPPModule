/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:32:58 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/10/27 14:42:36 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: AForm("Shrubbery Creation", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructed called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs)
        throw std::ios_base::failure("Failed to create shrubbery file");

    ofs << "       _-_\n"
           "    /~~   ~~\\\n"
           " /~~         ~~\\\n"
           "{               }\n"
           " \\  _-     -_  /\n"
           "   ~  \\\\ //  ~\n"
           "_- -   | | _- _\n"
           "  _ -  | |   -_\n"
           "      // \\\\\n";

    ofs.close();

    std::cout << executor.getName()
              << " executed ShrubberyCreationForm" << std::endl;
}
