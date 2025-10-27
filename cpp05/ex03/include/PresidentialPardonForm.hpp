/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:33:48 by kotasakatsu       #+#    #+#             */
/*   Updated: 2025/10/24 13:26:37 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;
public:
    PresidentialPardonForm(std::string const &target);
    virtual ~PresidentialPardonForm();
    void execute(Bureaucrat const &executor) const;
};

#endif