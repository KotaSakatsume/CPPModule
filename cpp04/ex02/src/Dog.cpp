/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:10:57 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/10/18 20:47:46 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain(); 
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other)
{
    type = other.type;         
    brain = new Brain(*other.brain);    
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
    if (this != &other) {
        type = other.type;
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Dog copy assignment operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof🐶" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea) {
    brain->setIdea(index, idea);
}

const std::string& Dog::getIdea(int index) const {
    return brain->getIdea(index);
}

Dog::~Dog(){
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}
