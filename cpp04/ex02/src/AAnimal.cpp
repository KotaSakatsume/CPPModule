/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:37:46 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/10/19 12:31:51 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal():type("Animal")
{
    std::cout << "Animal constructor called" << std::endl;
}

AAnimal::~AAnimal(){
    std::cout << "Animal destructor called" << std::endl;
}

const std::string& AAnimal::getType() const {
    return type;
}

void AAnimal::makeSound() const {
    std::cout << "Some generic animal sound" << std::endl;
}
