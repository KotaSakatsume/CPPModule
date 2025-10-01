/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:39:19 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/01 12:56:45 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* z;
	int N;

	N = 5;
	std::string name = "kota";
	
	z = zombieHorde(N, name);
	for(int i = 0; N > i; i++)
		z -> announce();
	delete[] z;
	return(0);
}
