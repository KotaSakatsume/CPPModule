/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotasakatsume <kotasakatsume@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:21:51 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/10/23 18:01:42 by kotasakatsu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name),_isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1) {
    	throw GradeTooHighException();
    }
	if (gradeToSign > 150 || gradeToExecute > 150) {
    	throw GradeTooLowException();
    }
    std::cout << "AForm constructed!" << std::endl;
}

AForm::AForm(const AForm &other)
	: _name(other._name),_isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "AForm Copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm destructed called" << std::endl;
}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if(_isSigned == true)
        return;
    if (b.getGrade() > getGradeToSign())
        throw GradeTooLowException();
    _isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
    out << f.getName()
        << ", signed: " << (f.getIsSigned() ? "true" : "false")
        << ", grade to sign: " << f.getGradeToSign()
        << ", grade to execute: " << f.getGradeToExecute()
        << ".";
    return out;
}
