/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:40:20 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/22 17:26:58 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat a("kosakats", 1);
		std::cout << a << std::endl;
		std::cout << a.getName() << std::endl;
		std::cout << a.getGrade() << std::endl;
		a.incrementGrade();
		std::cout << a.getGrade() << std::endl;
		
		// std::cout << "---------------------" << std::endl;
	
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "---------------------" << std::endl;

		try {
		Bureaucrat a("kosakats", 150);
		std::cout << a << std::endl;
		std::cout << a.getName() << std::endl;
		std::cout << a.getGrade() << std::endl;
		a.decrementGrade();
		std::cout << a.getGrade() << std::endl;
		
		// std::cout << "---------------------" << std::endl;
	
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}