/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:03:45 by kosakats          #+#    #+#             */
/*   Updated: 2025/12/20 14:21:05 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
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

	try {
		std::cout << "Finding 5... ";
		std::vector<int>::iterator it = easyfind(v, 5);
		std::cout << "Found: " << *it << " at index " << std::distance(v.begin(), it) << std::endl;

		std::cout << "Finding 42... ";
		easyfind(v, 42);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
