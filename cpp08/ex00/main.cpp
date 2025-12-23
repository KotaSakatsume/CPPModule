/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:03:45 by kosakats          #+#    #+#             */
/*   Updated: 2025/12/23 16:46:26 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "easyfind.hpp"

template <typename T>
void printContainer(const T& container) {
    std::cout << "Container: [ ";
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
	printContainer(v);

	std::cout << "--- Testing std::vector ---" << std::endl;
	try {
		std::cout << "Finding 5... ";
		std::vector<int>::iterator it = easyfind(v, 5);
		std::cout << "Found: " << *it << " at index " << std::distance(v.begin(), it) << std::endl;

		std::cout << "Finding 42... ";
		easyfind(v, 42);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing std::list ---" << std::endl;
	std::list<int> l(arr, arr + sizeof(arr) / sizeof(int));
	printContainer(l);

	try {
		std::cout << "Finding 7 in list... ";
		std::list<int>::iterator it = easyfind(l, 7);
		std::cout << "Found: " << *it << std::endl;

		std::cout << "Finding 100 in list... ";
		easyfind(l, 100);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
