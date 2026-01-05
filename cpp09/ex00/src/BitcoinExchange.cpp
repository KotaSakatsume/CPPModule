/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:00:36 by kosakats          #+#    #+#             */
/*   Updated: 2026/01/05 18:53:34 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	loadDatabase();
}

void BitcoinExchange::loadDatabase()
{
	std::ifstream file("cpp_09/data.csv");
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database.");

	std::string line;

	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::string date;
		std::string rateStr;

		std::stringstream ss(line);
		if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
			continue;
		double rate = std::atof(rateStr.c_str());
		_data[date] = rate;
	}
}

double BitcoinExchange::getRateForDate(const std::string& date) const
{
	
}
