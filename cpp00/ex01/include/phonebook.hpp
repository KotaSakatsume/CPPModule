/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 21:15:06 by kosakats          #+#    #+#             */
/*   Updated: 2025/09/25 18:22:57 by kosakats         ###   ########.fr       */
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
    int count;       // 現在の件数（0〜8）
    int nextIndex;   // 次に上書きする場所

public:
    PhoneBook();

    void addContact(const Contact& c);    // 新しい連絡先を追加
    void showContacts() const;            // 一覧表示
    void showContact(int index) const;    // 詳細表示
    int getCount() const;                 // 現在の件数を取得
};

#endif

