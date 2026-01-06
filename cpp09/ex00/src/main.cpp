/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotasakatsume <kotasakatsume@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:00:47 by kosakats          #+#    #+#             */
/*   Updated: 2026/01/06 18:49:31 by kotasakatsu      ###   ########.fr       */
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

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		data.processLine(line);
	}
	return (0);
}
