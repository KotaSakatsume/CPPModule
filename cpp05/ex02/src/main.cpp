/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotasakatsume <kotasakatsume@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:40:20 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/23 18:31:22 by kotasakatsu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{ 
	Bureaucrat a("Alice", 50);
	Bureaucrat b("Bob", 120);
	

	AForm taxAForm("TaxAForm", 75, 100);

	try {
       taxAForm.beSigned(a);
       std::cout << taxAForm << std::endl;
	} 
	catch (std::exception &e) {
       std::cout << e.what() << std::endl;
	}

	try {
    	taxAForm.beSigned(b); 
    	std::cout << taxAForm << std::endl;
   	} 
	catch (std::exception &e) {
   		std::cout << e.what() << std::endl;
   	}

	std::cout << "Final AForm state: " << taxAForm << std::endl;

}