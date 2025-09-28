/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:52:54 by kosakats          #+#    #+#             */
/*   Updated: 2025/09/28 21:56:03 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iomanip>  // std::setw
#include <iostream>
#include <string>

PhoneBook::PhoneBook() : count(0), nextIndex(0) {}

void PhoneBook::addContact(const Contact &c) 
{
    contacts[nextIndex] = c;
    nextIndex = (nextIndex + 1) % 8;
    if (count < 8)
        count++;
}


std::string format(const std::string &s) 
{
    if (s.length() > 10)
        return s.substr(0, 9) + ".";
    else
        return s;
}

void PhoneBook::showContacts() const 
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|"
              << std::setw(10) << "PhoneNumbe" << "|" << std::endl;

    for (int i = 0; i < count; i++) 
	{
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << format(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << format(contacts[i].getLastName()) << "|"
                  << std::setw(10) << format(contacts[i].getNickname()) << "|"
                  << std::setw(10) << format(contacts[i].getPhoneNumber()) << "|" << std::endl;
    }
    
}

void PhoneBook::showContact(int index) const 
{
    if (index < 0 || index >= count) 
	{
        std::cout << "Invalid index" << std::endl;
        return;
    }
    std::string input;
    std::getline(std::cin, input);

    const Contact &c = contacts[index];
    std::cout << "First Name: " << c.getFirstName() << std::endl;
    std::cout << "Last Name: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickname() << std::endl;
    std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}

int PhoneBook::getCount() const 
{
    return (count);
}
