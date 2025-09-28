/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 21:15:06 by kosakats          #+#    #+#             */
/*   Updated: 2025/09/28 14:50:22 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>

class PhoneBook {
private:
    static const int MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    int count;
    int nextIndex;

public:
    PhoneBook();

    void addContact(const Contact& c);
    void showContacts() const;
    void showContact(int index) const;
    int getCount() const;
};

#endif

