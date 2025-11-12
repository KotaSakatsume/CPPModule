/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotasakatsume <kotasakatsume@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:21:23 by kosakats          #+#    #+#             */
/*   Updated: 2025/11/12 16:34:51 by kotasakatsu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>
#include <string>

template <typename T, typename F>
void iter(const T* array, const size_t length, F func)
{
    if (!array || length == 0)
        return;
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

#endif
