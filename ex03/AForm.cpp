/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshevche <pshevche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:08:40 by pshevche          #+#    #+#             */
/*   Updated: 2023/12/03 16:08:41 by pshevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute, const std::string &target)
    : _name(name), _isSigned(false), _gradeRequiredToSign(gradeToSign),
      _gradeRequiredToExecute(gradeToExecute), _target(target) {
    if (gradeToSign < 1 || gradeToExecute < 1) throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150) throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name), _isSigned(other._isSigned), _gradeRequiredToSign(other._gradeRequiredToSign), _gradeRequiredToExecute(other._gradeRequiredToExecute) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

const std::string &AForm::getName() const { 
    return _name; 
}

const std::string &AForm::getTarget() const { 
    return _target; 
}

bool AForm::isSigned() const { 
    return _isSigned; 
}

int AForm::getGradeRequiredToSign() const { 
    return _gradeRequiredToSign; 
}

int AForm::getGradeRequiredToExecute() const { 
    return _gradeRequiredToExecute; 
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeRequiredToSign) {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << "AForm " << form.getName() << ", is signed: " << (form.isSigned() ? "yes" : "no")
        << ", grade required to sign: " << form.getGradeRequiredToSign()
        << ", grade required to execute: " << form.getGradeRequiredToExecute();
    return out;
}

void AForm::validateExecution(const Bureaucrat &executor) const {
    if (!_isSigned) {
        throw std::runtime_error("Form is not signed.");
    }
    if (executor.getGrade() > _gradeRequiredToExecute) {
        throw GradeTooLowException();
    }
}
