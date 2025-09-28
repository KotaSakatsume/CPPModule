/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:20:34 by kosakats          #+#    #+#             */
/*   Updated: 2025/09/28 21:46:10 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void Contact::setFirstName(std::string str) 
{ 
	firstName = str; 
}
void Contact::setLastName(std::string str) 
{ 
	lastName = str; 
}
void Contact::setNickname(std::string str) 
{ 
	nickname = str; 
}
void Contact::setPhoneNumber(std::string str) 
{ 
	phoneNumber = str; 
}
void Contact::setDarkestSecret(std::string str) 
{ 
	darkestSecret = str; 
}

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }
