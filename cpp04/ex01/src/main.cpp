/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:36:21 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/10/19 13:14:50 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << std::endl;

    delete dog;
    delete cat;

    std::cout << "-----------------------------" << std::endl;

    Dog basic;
    basic.setIdea(0, "Chasing the ball!");
    std::cout << "basic's first idea: " << basic.getIdea(0) << std::endl;

    std::cout << "----- Copy test -----" << std::endl;
    Dog copy = basic;

    std::cout << "copy's first idea: " << copy.getIdea(0) << std::endl;
    copy.setIdea(0, "Eating treats!");

    std::cout << "After change:" << std::endl;
    std::cout << "basic's first idea: " << basic.getIdea(0) << std::endl;
    std::cout << "copy's first idea: " << copy.getIdea(0) << std::endl;

    std::cout << "-----------------------------" << std::endl;

    return 0;
}

