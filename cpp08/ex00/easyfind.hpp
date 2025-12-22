/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:32:26 by kosakats          #+#    #+#             */
/*   Updated: 2025/12/20 14:19:51 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
	{
		throw std::out_of_range("Value not found in container");
	}
	return (it);
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
	{
		throw std::out_of_range("Value not found in container");
	}
	return (it);
}

#endif
