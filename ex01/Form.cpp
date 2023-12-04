/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:28:49 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/04 19:06:34 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, int grade_to_sign, int grade_to_execute): name(name), form_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
    std::cout << "Default constructor called" << std::endl;
    if (grade_to_sign < 1 || grade_to_execute < 1) throw GradeTooHighException();
    if (grade_to_sign > 150 || grade_to_execute > 150) throw GradeTooLowException();
}

Form::~Form()
{
    std::cout << "Destructor called" << std::endl;
}

std::string Form::get_name() const
{
    return (name);
}

int Form::get_grade_to_sign() const
{
    return (grade_to_sign);
}

int Form::get_grade_to_execute() const
{
    return (grade_to_sign);
}

std::string Form::get_signed() const
{
    if (form_signed == true)
        return ("Yes");
    else
        return ("No");
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.get_grade() >= grade_to_sign) {
        throw GradeTooLowException();
    }
    form_signed = true;
    return ;
}

std::ostream &operator<<( std::ostream & ost, Form const &form)
{
	ost << form.get_name() << ", grade to sign: " << form.get_grade_to_sign() << ", grade to execute: " << form.get_grade_to_execute() << ", signed: " << form.get_signed() << std::endl;
	return ost;
}