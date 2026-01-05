/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:00:27 by kosakats          #+#    #+#             */
/*   Updated: 2026/01/05 18:39:20 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
private:
	std::map<std::string, double> _data;
	void loadDatabase();
	double getRateForDate(const std::string& date) const;
	bool validateDate(const std::string& date) const;
	bool validateValue(const std::string& value) const;

public:
	BitcoinExchange();
	void processLine(const std::string& line);
};

#endif
