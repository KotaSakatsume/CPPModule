/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 14:43:38 by kosakats          #+#    #+#             */
/*   Updated: 2025/12/23 15:15:59 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

/* ---------- Basic subject test ---------- */
void test_subject()
{
	std::cout << "=== Subject Test ===" << std::endl;
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest : " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

/* ---------- Exception: empty / one element ---------- */
void test_exception_span()
{
	std::cout << "=== Exception Span Test ===" << std::endl;
	try
	{
		Span sp(5);
		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

/* ---------- Exception: addNumber overflow ---------- */
void test_overflow()
{
	std::cout << "=== Overflow Test ===" << std::endl;
	try
	{
		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4); // should throw
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

/* ---------- Iterator range test (vector) ---------- */
void test_iterator_vector()
{
	std::cout << "=== Iterator Vector Test ===" << std::endl;
	Span sp(10);

	std::vector<int> v;
	v.push_back(100);
	v.push_back(200);
	v.push_back(300);
	v.push_back(400);

	sp.addNumber(v.begin(), v.end());

	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest : " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

/* ---------- Iterator range test (list) ---------- */
void test_iterator_list()
{
	std::cout << "=== Iterator List Test ===" << std::endl;
	Span sp(10);

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(25);
	lst.push_back(40);

	sp.addNumber(lst.begin(), lst.end());

	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest : " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

/* ---------- Exception: iterator overflow ---------- */
void test_iterator_overflow()
{
	std::cout << "=== Iterator Overflow Test ===" << std::endl;
	try
	{
		Span sp(3);
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		sp.addNumber(v.begin(), v.end()); // should throw
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

/* ---------- Large test (10,000 numbers) ---------- */
void test_large()
{
	std::cout << "=== Large Test (10000) ===" << std::endl;
	Span sp(10000);
	std::vector<int> v;

	std::srand(std::time(NULL));
	for (int i = 0; i < 10000; ++i)
		v.push_back(std::rand());

	sp.addNumber(v.begin(), v.end());

	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest : " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

/* ---------- main ---------- */
int main()
{
	test_subject();
	test_exception_span();
	test_overflow();
	test_iterator_vector();
	test_iterator_list();
	test_iterator_overflow();
	test_large();

	return 0;
}

