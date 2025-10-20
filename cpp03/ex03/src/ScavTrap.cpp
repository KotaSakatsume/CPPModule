/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:26:22 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/16 16:26:23 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructed!\n";
}

// コピーコンストラクタ
ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other) {
	*this = other;
	std::cout << "ScavTrap copy constructed!\n";
}

// 代入演算子
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other); // ClapTrap部分のコピー
	}
	std::cout << "ScavTrap copy assigned!\n";
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destructed!\n";
}

void ScavTrap::attack(const std::string& target) {
	std::cout << "ScavTrap " << _name
			  << " fiercely attacks " << target
			  << ", dealing " << _attackDamage << " damage!\n";
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " has entered Gate Keeper mode!\n";
}
