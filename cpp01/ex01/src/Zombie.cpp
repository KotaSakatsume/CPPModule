/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:30:58 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/01 11:36:02 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


// デフォルトコンストラクタ
Zombie::Zombie() {}

// 名前付きコンストラクタ
Zombie::Zombie(std::string name) : name(name) {}

// デストラクタ（ゾンビが消えるときに表示）
Zombie::~Zombie()
{
    std::cout << name << " is destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string n)
{
    name = n;
}
