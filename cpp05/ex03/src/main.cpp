/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:46:14 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/27 19:58:51 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat boss("Alice", 1);
		Intern someRandomIntern;

        std::cout << "\n=== form1 ===\n";
		AForm *form1 = someRandomIntern.makeForm("robotomy request", "Bender");
		if (form1)
		{
        
			form1->beSigned(boss);
			boss.executeForm(*form1);
			delete form1;
		}

        std::cout << "\n=== form2 ===\n";
		AForm *form2 = someRandomIntern.makeForm("shrubbery creation", "home");
		if (form2)
		{

			form2->beSigned(boss);
			boss.executeForm(*form2);
			delete form2;
		}

        std::cout << "\n=== form3 ===\n";
		AForm *form3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
		if (form3)
		{

			form3->beSigned(boss);
			boss.executeForm(*form3);
			delete form3;
		}

        std::cout << "\n=== form4 ===\n";
		AForm *form4 = someRandomIntern.makeForm("coffee request", "kosa");
		if (form4)
        {
			delete form4;
        }

	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
