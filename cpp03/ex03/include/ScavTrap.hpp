/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:36:35 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/16 18:10:20 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);              
	ScavTrap& operator=(const ScavTrap& other);    
	virtual ~ScavTrap();

    virtual void attack(const std::string& target);
	void guardGate();
};

#endif
