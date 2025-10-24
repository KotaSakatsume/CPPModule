/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:33:26 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/10/24 19:35:06 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	: AForm("Robotomy Request", 72, 45), _target(target)
{
	    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructed called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if(executor.getGrade() > getGradeToExecute()) {
		std::cout << "NG" << std::endl;
		return;
	}
	std::cout << "OK" << std::endl;
	return;
}
