/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:28:26 by kosakats          #+#    #+#             */
/*   Updated: 2025/11/06 16:53:26 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>

struct Data;

class Serializer
{
private:
    Serializer();
    Serializer(const Serializer &);
    Serializer &operator=(const Serializer &);
    ~Serializer();
public:
	static __intptr_t serialize(Data* ptr);
	static Data* deserialize(__intptr_t raw);
};

#endif