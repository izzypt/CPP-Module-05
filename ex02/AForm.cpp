/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:12:00 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/04 20:29:03 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute, const std::string &target)
    : name(name), is_signed(false), grade_to_sign(gradeToSign),
      grade_to_execute(gradeToExecute), target(target) {
    if (gradeToSign < 1 || gradeToExecute < 1) throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150) throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        is_signed = other.is_signed;
    }
    return *this;
}

const std::string &AForm::getName() const { 
    return name; 
}

const std::string &AForm::get_target() const { 
    return target; 
}

bool AForm::isSigned() const { 
    return is_signed; 
}

int AForm::get_grade_to_sign() const { 
    return grade_to_sign; 
}

int AForm::get_grade_to_execute() const { 
    return grade_to_execute; 
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.get_grade() > grade_to_sign) {
        throw GradeTooLowException();
    }
    is_signed = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << "AForm " << form.getName() << ", is signed: " << (form.isSigned() ? "yes" : "no")
        << ", grade required to sign: " << form.get_grade_to_sign()
        << ", grade required to execute: " << form.get_grade_to_execute();
    return out;
}

void AForm::validateExecution(const Bureaucrat &executor) const {
    if (!is_signed) {
        throw std::runtime_error("Form is not signed.");
    }
    if (executor.get_grade() > grade_to_execute) {
        throw GradeTooLowException();
    }
}