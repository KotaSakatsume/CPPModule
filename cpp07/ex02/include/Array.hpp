/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotasakatsume <kotasakatsume@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:38:31 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/11/12 18:42:22 by kotasakatsu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>

template <typename T>

class Array
{
private:
    T* _array;
    unsigned int _size;
public:
    Array();
    Array(const unsigned int n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();
    unsigned int size() const
    
};

#endif