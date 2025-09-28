/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:11:33 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/09/28 21:54:02 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

bool isNumber(const std::string& s) 
{
    if (s.empty()) 
        return (false);
    for (size_t i = 0; i < s.size(); i++) 
    {
        if (!std::isdigit(s[i])) 
            return (false);
    }
    return (true);
}

int toInt(const std::string& s) 
{
    int num = 0;
    for (size_t i = 0; i < s.size(); i++) 
    {
        num = num * 10 + (s[i] - '0');
    }
    return (num);
}

bool isEmptyOrSpaces(const std::string &str)
{
    if (str.empty())
        return true;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!isspace(str[i]))
            return false;
    }
    return true;
}


int main() 
{
    PhoneBook pb;
    std::string cmd;

    while (true) 
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, cmd);

        if (cmd == "ADD") 
        {
            Contact c;
            std::string str;

            std::cout << "First name: ";
            std::getline(std::cin, str);
            if (isEmptyOrSpaces(str))
                continue;
            c.setFirstName(str);

            std::cout << "Last name: ";
            std::getline(std::cin, str);
            if (isEmptyOrSpaces(str))
                continue;
            c.setLastName(str);

            std::cout << "Nickname: ";
            std::getline(std::cin, str);
            if (isEmptyOrSpaces(str))
                continue;
            c.setNickname(str);

            std::cout << "Phone number: ";
            std::getline(std::cin, str);
            if (isEmptyOrSpaces(str))
                continue;
            c.setPhoneNumber(str);
            
            std::cout << "Darkest Secret: ";
            std::getline(std::cin, str);
            if (isEmptyOrSpaces(str))
                continue;
            c.setDarkestSecret(str);

            pb.addContact(c);
            std::cout << "Contact added!" << std::endl;
        }
        else if (cmd == "SEARCH") 
        {   
            pb.showContacts();
            if (pb.getCount() == 0)
                continue;
    
            std::cout << "Enter index to view: ";
            std::string input;
            std::cin >> input;
    
            if (!isNumber(input)) 
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number." << std::endl;
                continue;
            }
    
            int index = toInt(input);
            if (index >= 0 && index <= 9)
                pb.showContact(index);
            else
                std::cout << "Invalid index." << std::endl;
        }
        else if (cmd == "EXIT") 
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else 
        {
            std::cout << "Unknown command" << std::endl;
        }
    }
    return (0);
}
