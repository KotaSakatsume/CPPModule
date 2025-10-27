/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:33:59 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/10/27 14:45:47 by kosakats         ###   ########.fr       */
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
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    std::cout << executor.getName() << " executed PresidentialPardonForm" << std::endl;
}
