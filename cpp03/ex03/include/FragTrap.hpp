/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:08:04 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/16 18:10:09 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);            
	FragTrap& operator=(const FragTrap& other);
	virtual ~FragTrap();
	
	void highFivesGuys(void);
};

#endif
