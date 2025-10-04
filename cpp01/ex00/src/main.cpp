/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:58:28 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/04 13:57:54 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    Zombie* z1 = newZombie("HeapZombie");
    if(!z1)
    {
        std::cerr << "Failed to allocate memory." << std::endl;
        return(1);
    }
    z1->announce();
    delete z1;

    randomChump("StackZombie");

    return 0;
}
