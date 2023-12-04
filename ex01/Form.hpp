/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:27:02 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/04 19:08:54 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string.h>
#include "Bureaucrat.hpp"

class Form 
{
    private:
        std::string const name;
        bool form_signed;
        int const grade_to_sign;
        int const grade_to_execute;

    public:
        Form(const std::string &name, int grade_to_sign, int grade_to_execute);
        ~Form();
		std::string Form::get_name() const;
		int Form::get_grade_to_sign() const;
		int Form::get_grade_to_execute() const;
		std::string Form::get_signed() const;
        void beSigned(const Bureaucrat &bureaucrat);
		class GradeTooHighException : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif