/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:20:13 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/19 13:26:56 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
private:
    std::string ideas[100]; 
public:
    Brain();                             
    Brain(const Brain &other);          
    Brain& operator=(const Brain &other); 
    const std::string& getIdea(int index) const; 
    void setIdea(int index, const std::string &idea); 
    ~Brain();                          
};


#endif