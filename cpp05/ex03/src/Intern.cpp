/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:14:34 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/27 19:51:13 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Intern constructed called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructed called" << std::endl;
}

static AForm* createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*formCreators[3])(const std::string &) = {
		&createShrubbery,
		&createRobotomy,
		&createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](target);
		}
	}

	std::cout << "Form name \"" << formName << "\" does not exist" << std::endl;
	return NULL;
}
