/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:28:49 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/04 14:39:36 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
{
    std::cout << "Default constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Destructor called" << std::endl;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() >= grade)
        form_signed = true;
    else
        throw(GradeTooLowException());
}
