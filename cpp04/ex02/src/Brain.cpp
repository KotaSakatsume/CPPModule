/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:39:54 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/18 16:25:40 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for(int i = 0; i < 100; i++)
		ideas[i] = "default idea";
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
	{
        for (int i = 0; i < 100; i++) 
			ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy assignment operator called" << std::endl;
    return *this;
}

const std::string& Brain::getIdea(int index) const {
	return ideas[index];
}

void Brain::setIdea(int index, const std::string &idea) {
	 ideas[index] = idea;
	std::cout << "Idea set at index " << index << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}