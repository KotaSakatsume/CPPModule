/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotasakatsume <kotasakatsume@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:21:51 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/10/23 18:01:42 by kotasakatsu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name),_isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1) {
    	throw GradeTooHighException();
    }
	if (gradeToSign > 150 || gradeToExecute > 150) {
    	throw GradeTooLowException();
    }
    std::cout << "Form constructed!" << std::endl;
}

Form::Form(const Form &other)
	: _name(other._name),_isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form Copy constructor called" << std::endl;
}

Form& Form::operator=(const Form &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructed called" << std::endl;
}

std::string Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &b)
{
    if(_isSigned == true)
        return;
    if (b.getGrade() > getGradeToSign())
        throw GradeTooLowException();
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
    out << f.getName()
        << ", signed: " << (f.getIsSigned() ? "true" : "false")
        << ", grade to sign: " << f.getGradeToSign()
        << ", grade to execute: " << f.getGradeToExecute()
        << ".";
    return out;
}
