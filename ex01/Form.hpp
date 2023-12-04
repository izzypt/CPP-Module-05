/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:27:02 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/04 14:27:12 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string.h>
#include "Bureaucrat.hpp"

class Form 
{
    public:
        Form();
        ~Form();
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

    private:
        bool form_signed;
        std::string const name;
        int const grade;
};

#endif