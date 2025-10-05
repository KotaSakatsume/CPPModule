/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:48:32 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/05 16:12:52 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    try
    {
        return new Zombie(name);
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "Failed to allocate memory for Zombie: " << e.what() << std::endl;
        return NULL;
    }
}

