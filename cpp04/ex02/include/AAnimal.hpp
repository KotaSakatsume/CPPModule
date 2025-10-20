/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:37:20 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/10/19 12:17:16 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal{
protected:
    std::string type;
public:
    AAnimal();
    const std::string& getType() const;
    virtual void makeSound() const = 0;
    virtual ~AAnimal();
};

#endif