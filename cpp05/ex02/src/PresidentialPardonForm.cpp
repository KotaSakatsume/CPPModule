/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:33:59 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/10/24 19:35:23 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
    : AForm("Presidential Pardon", 25, 5), _target(target)
{
	    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructed called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if(executor.getGrade() > getGradeToExecute()) {
		std::cout << "NG" << std::endl;
		return;
	}
	std::cout << "OK" << std::endl;
	return;
}
