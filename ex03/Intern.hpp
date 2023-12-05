/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 00:03:54 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/05 00:04:06 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
public:
    Intern();
    ~Intern();
    AForm* makeForm(const std::string &formName, const std::string &target) const;

private:
    AForm* createShrubberyCreationForm(const std::string &target) const;
    AForm* createRobotomyRequestForm(const std::string &target) const;
    AForm* createPresidentialPardonForm(const std::string &target) const;
};

#endif