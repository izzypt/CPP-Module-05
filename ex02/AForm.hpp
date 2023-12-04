/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:57:31 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/04 23:24:47 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool is_signed;
    const int grade_to_sign;
    const int grade_to_execute;
    const std::string target;

public:
    AForm(const std::string &name, int gradeToSign, int gradeToExecute, const std::string &target);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    const std::string &get_name() const;
    bool isSigned() const;
    int get_grade_to_sign() const;
    int get_grade_to_execute() const;
    const std::string &get_target() const;

    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(const Bureaucrat &executor) const = 0;

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw() {
            return "\e[0;38;5;9mForm Exception: Grade too high\n\e[0m";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw() {
            return "\e[0;38;5;9mForm Exception: Grade too low\n\e[0m";
        }
    };

    void validateExecution(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif