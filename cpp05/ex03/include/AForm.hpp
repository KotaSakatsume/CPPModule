/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:35:25 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/10/25 14:27:06 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm 
{
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
public:
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
	AForm &operator=(const AForm &other);
    virtual ~AForm();
    
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat &b);
    virtual void execute(Bureaucrat const &executor) const = 0;
    
    class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

    class FormNotSignedException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif
