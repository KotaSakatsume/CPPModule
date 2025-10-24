/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:40:20 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/24 19:27:28 by kosakats         ###   ########.fr       */
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
        clerk.signForm(shrub);   // 署名失敗
        boss.signForm(shrub);    // 署名成功
        boss.signForm(robot);    // 署名成功
        boss.signForm(pardon);   // 署名成功

        std::cout << "\n=== Executing Forms ===\n";
        shrub.execute(boss);     // 成功
        robot.execute(boss);     // 成功 or 失敗（50%）
        pardon.execute(boss);    // 成功

        // Bureaucrat 経由で実行
        // std::cout << "\n=== Executing via Bureaucrat ===\n";
        // boss.executeForm(shrub);
        // boss.executeForm(robot);
        // boss.executeForm(pardon);

        std::cout << "\n=== Destructed ===\n";


    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
