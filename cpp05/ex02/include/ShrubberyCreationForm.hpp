/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:32:48 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/10/24 16:52:02 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;
public:
    ShrubberyCreationForm(std::string const &target);
    virtual ~ShrubberyCreationForm();
    void execute(Bureaucrat const &executor) const;
};

#endif