/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:37:06 by kosakats          #+#    #+#             */
/*   Updated: 2025/11/14 19:24:17 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <streambuf>
#include <iostream>

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;      
    b = temp;   
}

template <typename T>
const T& min(const T& a, const T& b)
{
    return (a < b) ? a : b;
}

template <typename T>
const T& max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}

template void swap<int>(int&, int&);
template const int& min<int>(const int&, const int&);
template const int& max<int>(const int&, const int&);

template void swap<std::string>(std::string&, std::string&);
template const std::string& min<std::string>(const std::string&, const std::string&);
template const std::string& max<std::string>(const std::string&, const std::string&);


#endif
