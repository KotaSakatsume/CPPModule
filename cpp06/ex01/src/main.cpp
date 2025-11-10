/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:28:37 by kosakats          #+#    #+#             */
/*   Updated: 2025/11/06 16:57:52 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data data;
	data.id = 1;
	data.name = "Alice";

	__intptr_t raw = Serializer::serialize(&data);
	Data* ptr = Serializer::deserialize(raw);

	if (ptr == &data)
    	std::cout << "OK" << std::endl;
	else
    	std::cout << "NG" << std::endl;
	return 0;
}
