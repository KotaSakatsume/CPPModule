/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:38:31 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/11/14 17:35:02 by kosakats         ###   ########.fr       */
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
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    ~Array();
    unsigned int size() const;
    
};

#include "../src/Array.tpp"

#endif