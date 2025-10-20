/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:36:21 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/10/19 12:31:33 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    // const AAnimal a;

    std::cout << "=== Polymorphism Test ===" << std::endl;
    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();

    std::cout << std::endl;
    dog->makeSound(); 
    cat->makeSound(); 

    std::cout << std::endl;
    delete dog;
    delete cat;

    std::cout << "\n=== Deep Copy Test ===" << std::endl;

    Dog basic;
    basic.setIdea(0, "Chasing the ball!");
    std::cout << "basic's first idea: " << basic.getIdea(0) << std::endl;

    std::cout << "\n-- Copy constructor test --" << std::endl;
    Dog copy = basic;

    std::cout << "copy's first idea: " << copy.getIdea(0) << std::endl;

    copy.setIdea(0, "Eating treats!");

    std::cout << "\nAfter change:" << std::endl;
    std::cout << "basic's first idea: " << basic.getIdea(0) << std::endl;
    std::cout << "copy's first idea: " << copy.getIdea(0) << std::endl;

    std::cout << "\n=== Array of Animals Test ===" << std::endl;

    const AAnimal* animals[4];
    for (int i = 0; i < 2; i++)
        animals[i] = new Dog();
    for (int i = 2; i < 4; i++)
        animals[i] = new Cat();

    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
        animals[i]->makeSound();

    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
        delete animals[i];

    return 0;
}


