/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:29:16 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/12 19:55:43 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
{
	std::cout << "ClapTrap" << name << "has been generated!" << std::endl;
	_name = name;
}