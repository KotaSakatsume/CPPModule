/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotasakatsume <kotasakatsume@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:37:20 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/10/17 18:39:17 by kotasakatsu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal{
protected:
    std::string type;
public:
    Animal();
    const std::string& getType() const;
    virtual void makeSound() const;
    virtual ~Animal();
};

#endif