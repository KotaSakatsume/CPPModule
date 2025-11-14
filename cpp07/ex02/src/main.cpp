/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:38:14 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/11/14 17:35:07 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"

int main()
{
    Array<int> arr(5);

    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = i * 10;

    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;

    return 0;
}
