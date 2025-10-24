/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:32:58 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/10/24 19:34:37 by kosakats         ###   ########.fr       */
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
    if(executor.getGrade() > getGradeToExecute()) {
		std::cout << "NG" << std::endl;
		return;
	}
	std::cout << "OK" << std::endl;
	return;
}