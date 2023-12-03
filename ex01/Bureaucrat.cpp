/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:09:39 by simao             #+#    #+#             */
/*   Updated: 2023/12/03 17:42:42 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Default Constructor called for Bureaucrat" << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : m_name(name)
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
    m_grade = grade;
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
        this->m_name = b.getName();
        this->m_grade = b.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Default Destructor called for Bureaucrat" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return m_name;
}

int Bureaucrat::getGrade() const
{
    return m_grade;
}

void Bureaucrat::incGrade()
{
    if (m_grade == 1)
    {
        throw(GradeTooHighException());
    }
    else
        m_grade--;
}

void Bureaucrat::decGrade()
{
    if (m_grade == 150)
    {
        throw(GradeTooLowException());
    }
    else
       m_grade++;
}

std::ostream &operator<<(std::ostream &ost, Bureaucrat const &bur)
{
	ost << bur.getName() << ", bureaucrat grade: " << bur.getGrade();
	return ost;
}