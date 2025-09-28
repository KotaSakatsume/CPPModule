/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:20:16 by kosakats          #+#    #+#             */
/*   Updated: 2025/09/28 21:50:04 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <limits>
#include <iostream>
#include <string>
#include <cctype> 

class Contact 
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;


public:
    void setFirstName(std::string str);
    void setLastName(std::string str);
    void setNickname(std::string str);
    void setPhoneNumber(std::string str);
    void setDarkestSecret(std::string str);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif


