/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:26:10 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/04 22:28:13 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm 
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        virtual ~PresidentialPardonForm();

        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

        const std::string &getTarget() const;

        virtual void execute(const Bureaucrat &executor) const;
};

#endif