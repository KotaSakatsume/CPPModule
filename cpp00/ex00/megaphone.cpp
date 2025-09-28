/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:30:58 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/09/28 14:46:20 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <cctype>

int main(int argc, char **argv) 
{
    if (argc == 1) 
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; i++) 
    {
        std::string s2 = argv[i];
        for (size_t j = 0; j < s2.size(); j++) 
        {
            s2[j] = std::toupper(static_cast<unsigned char>(s2[j]));
        }
        std::cout << s2;
    }
    std::cout << std::endl;
    return 0;
}
