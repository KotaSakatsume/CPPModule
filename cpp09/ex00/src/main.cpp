/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:00:47 by kosakats          #+#    #+#             */
/*   Updated: 2026/01/05 18:24:31 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange data;
	if(argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	std::ifstream file(argv[1]);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return(1);
	}
		
	return (0);
}
