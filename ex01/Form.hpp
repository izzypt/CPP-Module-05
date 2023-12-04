/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:27:02 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/04 19:47:17 by smagalha         ###   ########.fr       */
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
		std::string get_name() const;
		int get_grade_to_sign() const;
		int get_grade_to_execute() const;
		std::string get_signed() const;
        void beSigned(const Bureaucrat &bureaucrat);
        class GradeTooHighException : public std::exception 
        {
            public:
                    virtual const char* what() const throw() 
                    {
                            return ("\e[0;38;5;9mForm Exception: Grade too high\n\e[0m");
                    }
        };
        class GradeTooLowException : public std::exception 
        {
            public:
                    virtual const char* what() const throw() 
                    {
                                    return ("\e[0;38;5;9mForm Exception: Grade too low\n\e[0m");
                
                    }
        };
        /*  The friend keyword here indicates that this function is not a member function of the Form class, 
            but it is allowed to access the private and protected members of the Form class */
        friend std::ostream &operator<<( std::ostream & ost, Form const &form);
};

#endif