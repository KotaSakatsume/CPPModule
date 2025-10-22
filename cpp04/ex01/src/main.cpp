/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:36:21 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/10/21 18:29:37 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    // const Animal a;

    std::cout << "=== Polymorphism Test ===" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

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

    const Animal* animals[4];
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

