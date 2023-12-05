/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:09:39 by simao             #+#    #+#             */
/*   Updated: 2023/12/04 23:44:13 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &_name, int grade) : name(_name)
{
    if (grade < 1)
    {
        throw(GradeTooHighException());
    }
    if (grade > 150)
    {
        throw(GradeTooLowException());
    }
    std::cout << "Constructor called for Bureaucrat" << std::endl;
    this->grade = grade;
    return ;

}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
    std::cout << "Copy Construtor called for Bureaucrat" << std::endl;
    *this = bureaucrat;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &b)
{
    std::cout << "Assignation operator called for Bureaucrat" << std::endl;
     if (this != &b)
    {
        this->name = b.get_name();
        this->grade = b.get_grade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Default Destructor called for Bureaucrat" << std::endl;
}

std::string Bureaucrat::get_name() const
{
    return name;
}

int Bureaucrat::get_grade() const
{
    return grade;
}

void Bureaucrat::inc_grade()
{
    if (grade == 1)
    {
        throw(GradeTooHighException());
    }
    else
        grade--;
}

void Bureaucrat::dec_grade()
{
    if (grade == 150)
    {
        throw(GradeTooLowException());
    }
    else
       grade++;
}

std::ostream &operator<<(std::ostream &ost, Bureaucrat const &bur)
{
	ost << bur.get_name() << ", bureaucrat grade: " << bur.get_grade();
	return ost;
}

void Bureaucrat::sign_form(AForm& aform) const
{
    try {
        aform.beSigned(*this);
        std::cout << name << " signed " << aform.get_name() << std::endl;
    } catch (const std::exception& e) {
        std::cout << name << " couldn’t sign " << aform.get_name() << " because " << e.what() << std::endl;
    }

}

void Bureaucrat::execute_form(AForm const & form)
{
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.get_name() << std::endl;
    } catch (std::exception & e) {
        std::cerr << name << " couldn’t execute " << form.get_name() << " because: " << e.what() << std::endl;
    }
}