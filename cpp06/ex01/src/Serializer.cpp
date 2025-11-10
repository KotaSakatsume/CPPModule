/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:28:30 by kosakats          #+#    #+#             */
/*   Updated: 2025/11/06 16:56:51 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &) {}
Serializer& Serializer::operator=(const Serializer &) {return *this;}
Serializer::~Serializer() {}

__intptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<__intptr_t>(ptr);
}

Data* Serializer::deserialize(__intptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
