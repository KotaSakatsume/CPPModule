/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:58:40 by kosakats          #+#    #+#             */
/*   Updated: 2025/11/07 19:08:12 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib> 
#include <ctime>    
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    std::srand(std::time(NULL));


    for (int i = 0; i < 5; i++)
    {
        std::cout << "---- Test " << (i + 1) << " ----" << std::endl;

        Base* ptr = generate(); 

        std::cout << "identify(Base*): ";
        identify(ptr);         

        std::cout << "identify(Base&): ";
        identify(*ptr);       

        delete ptr;           
        std::cout << std::endl;
    }

    return 0;
}


