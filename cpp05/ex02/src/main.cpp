/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:40:20 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/27 18:50:50 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        std::cout << "\n=== Constructed ===\n";
        Bureaucrat boss("Alice", 1);
        Bureaucrat clerk("Bob", 150);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Charlie");

        std::cout << "\n=== Signing Forms ===\n";
        clerk.signForm(shrub); 
        boss.signForm(shrub);  
        boss.signForm(robot);  
        boss.signForm(pardon); 

        std::cout << "\n=== Executing Forms ===\n";
        shrub.execute(boss);    
        robot.execute(boss);    
        pardon.execute(boss);

        std::cout << "\n=== Executing via Bureaucrat ===\n";
        boss.executeForm(shrub);
        boss.executeForm(robot);
        boss.executeForm(pardon);

    } catch (std::exception &e) {
        std::cout << "\n=== Exception handling ===\n";
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
