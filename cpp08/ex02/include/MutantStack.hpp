/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:18:51 by kosakats          #+#    #+#             */
/*   Updated: 2025/12/23 16:24:31 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {}
		~MutantStack() {}
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
};

#endif