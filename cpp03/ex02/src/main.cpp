/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:28:56 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/15 21:08:32 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

int main()
{
	std::cout << "=== Creating FragTrap ===" << std::endl;
	FragTrap frag("Rocky");

	std::cout << "\n=== Testing actions ===" << std::endl;
	frag.attack("enemy");
	frag.takeDamage(30);
	frag.beRepaired(20);
	frag.highFivesGuys();

	std::cout << "\n=== Destruction ===" << std::endl;
	return 0;
}


