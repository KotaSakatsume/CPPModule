/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotasakatsume <kotasakatsume@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:30:58 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/09/23 16:29:00 by kotasakatsu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>

int main(int argc, char **argv) 
{
    if (argc != 2) 
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
  std::string s2 = argv[1]; 

  for (size_t i = 0; i < s2.size(); i++) 
  {
    s2[i] = std::toupper(s2[i]);
  }


  std::cout << "s2 = " << s2 << std::endl;
}
