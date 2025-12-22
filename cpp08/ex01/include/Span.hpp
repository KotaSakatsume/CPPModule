/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 14:43:13 by kosakats          #+#    #+#             */
/*   Updated: 2025/12/22 17:33:34 by kosakats         ###   ########.fr       */
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

	private:
		std::vector<int> _numbers;
		unsigned int _maxSize;
};

#endif
