/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:37:06 by kosakats          #+#    #+#             */
/*   Updated: 2025/11/10 20:05:29 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <streambuf>
#include <iostream>

template <typename T>
void swap(T& a, T& b);

template <typename T>
const T& min(const T& a, const T& b);

template <typename T>
const T& max(const T& a, const T& b);

#endif
