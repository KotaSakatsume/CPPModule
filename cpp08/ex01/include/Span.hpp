/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 14:43:13 by kosakats          #+#    #+#             */
/*   Updated: 2025/12/23 15:10:11 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Span
{
	public:
		Span();
		Span(unsigned int N);
		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
		void print();

		template<typename iterator>
		void addNumber(iterator begin, iterator end)
		{
			std::vector<int> copyNumbers = _numbers;
			if(_numbers.size() + std::distance(begin, end) > _maxSize)
        		throw std::runtime_error("Span is full");
			copyNumbers.insert(copyNumbers.end(), begin, end);
			_numbers = copyNumbers;
		}
		
	private:
		std::vector<int> _numbers;
		unsigned int _maxSize;
};

#endif
