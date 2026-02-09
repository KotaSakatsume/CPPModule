/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotasakatsume <kotasakatsume@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:00:36 by kosakats          #+#    #+#             */
/*   Updated: 2026/01/07 14:43:04 by kotasakatsu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	loadDatabase();
}

BitcoinExchange::~BitcoinExchange() {}

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
    std::map<std::string, double>::const_iterator it;

    it = _data.lower_bound(date);

    if (it != _data.end() && it->first == date)
        return it->second;

    if (it == _data.begin())
        throw std::runtime_error("Error: no earlier date available.");

    --it;
    return it->second;
}

bool BitcoinExchange::validateDate(const std::string& date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	if (yearStr.find_first_not_of("0123456789") != std::string::npos ||
		monthStr.find_first_not_of("0123456789") != std::string::npos ||
		dayStr.find_first_not_of("0123456789") != std::string::npos)
		return false;

	int year = std::atoi(yearStr.c_str());
	int month = std::atoi(monthStr.c_str());
	int day = std::atoi(dayStr.c_str());

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	if (month == 2)
	{
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (isLeap ? 29 : 28))
			return false;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return false;
	}
	return true;
}

bool BitcoinExchange::validateValue(const std::string& value) const
{
	char* end;
	std::strtod(value.c_str(), &end);
	return *end == '\0' && !value.empty();
}

void BitcoinExchange::processLine(const std::string& line)
{
	size_t delim = line.find('|');
	if (delim == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}

	std::string date = line.substr(0, delim);
	std::string valueStr = line.substr(delim + 1);

	size_t first = date.find_first_not_of(" \t");
	size_t last = date.find_last_not_of(" \t");
	if (first == std::string::npos)
		date = "";
	else
		date = date.substr(first, (last - first + 1));

	first = valueStr.find_first_not_of(" \t");
	last = valueStr.find_last_not_of(" \t");
	if (first == std::string::npos)
		valueStr = "";
	else
		valueStr = valueStr.substr(first, (last - first + 1));

	if (!validateDate(date))
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return;
	}

	if (!validateValue(valueStr))
	{
		std::cout << "Error: bad input => " << valueStr << std::endl;
		return;
	}

	double value = std::atof(valueStr.c_str());

	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return;
	}
	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return;
	}

	try
	{
		double rate = getRateForDate(date);
		std::cout << date << " => " << value << " = " << value * rate << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
