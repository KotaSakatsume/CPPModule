/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:52:54 by kosakats          #+#    #+#             */
/*   Updated: 2025/09/27 11:16:30 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iomanip>  // std::setw
#include <iostream>
#include <string>

PhoneBook::PhoneBook() : count(0), nextIndex(0) {}

// 新しい連絡先を追加
void PhoneBook::addContact(const Contact &c) 
{
    contacts[nextIndex] = c;
    nextIndex = (nextIndex + 1) % 8;  // 8件でループ
    if (count < 8)
        count++;
}

// 10文字以内に整形する関数
std::string format(const std::string &s) 
{
    if (s.length() > 10)
        return s.substr(0, 9) + ".";
    else
        return s;
}

// 一覧表示
void PhoneBook::showContacts() const 
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|"
              << std::setw(10) << "PhoneNumbe" << "|"
              << std::setw(10) << "DarkestSec" << "|" << std::endl;

    for (int i = 0; i < count; i++) 
	{
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << format(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << format(contacts[i].getLastName()) << "|"
                  << std::setw(10) << format(contacts[i].getNickname()) << "|"
                  << std::setw(10) << format(contacts[i].getPhoneNumber()) << "|"
                  << std::setw(10) << format(contacts[i].getDarkestSecret()) << "|" << std::endl;
    }
    
}

// 詳細表示
void PhoneBook::showContact(int index) const 
{
    if (index < 0 || index >= count) 
	{
        std::cout << "Invalid index" << std::endl;
        return;
    }
    std::string input;
    std::cout << "Enter index to view (or just press Enter to go back): ";
    std::getline(std::cin, input);

    const Contact &c = contacts[index];
    std::cout << "First Name: " << c.getFirstName() << std::endl;
    std::cout << "Last Name: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickname() << std::endl;
    std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}

// 現在の件数を返す
int PhoneBook::getCount() const 
{
    return count;
}
