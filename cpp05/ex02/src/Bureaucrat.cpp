/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:40:34 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/24 19:22:46 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat():_name("unknown"), _grade(150)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(grade)
{
	if (grade < 1)
    	throw GradeTooHighException();
	if (grade > 150)
    	throw GradeTooLowException();
    std::cout << "Bureaucrat " << _name << "," << _grade << " constructed!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(other._grade)
{
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructed called" << std::endl;
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	_grade--;
	if (_grade < 1)
		throw GradeTooHighException();
	return;
}

void Bureaucrat::decrementGrade() {
	_grade++;
	if(_grade > 150)
		throw GradeTooLowException();
	return;
}

void Bureaucrat::signForm(AForm &form)
{
	if(_grade > form.getGradeToSign()) {
		std::cout << "NG" << std::endl;
		return;
	}
	std::cout << "OK" << std::endl;
	return;
}

// void Bureaucrat::executeForm(AForm const &form) const 
// {
// 	(void)form;
// }

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}
