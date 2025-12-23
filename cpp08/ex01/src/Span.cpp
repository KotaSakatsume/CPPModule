/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 14:43:09 by kosakats          #+#    #+#             */
/*   Updated: 2025/12/23 16:49:17 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
// A default-constructed Span has an uninitialized maxSize, which is a bug.
// It should be initialized, for example, to 0.
Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N)
{
    _numbers.reserve(N);
}

void Span::addNumber(int num)
{
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Span is full");
    _numbers.push_back(num);
}

void Span::print()
{
	for (std::vector<int>::iterator it = _numbers.begin(); it != _numbers.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Span cannot be found");

	std::vector<int> copyNumbers = _numbers;
	std::sort(copyNumbers.begin(), copyNumbers.end());

	int min = copyNumbers[1] - copyNumbers[0];
	for (std::vector<int>::iterator it = copyNumbers.begin();
	     it != copyNumbers.end() - 1; ++it)
	{
		int diff = *(it + 1) - *it;
		if (diff < min)
			min = diff;
	}
	return min;
}

int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Span cannot be found");
	
	// Using min_element and max_element is more efficient (O(N))
	// than copying and sorting (O(N log N)).
	return *std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end());
}
