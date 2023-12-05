/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshevche <pshevche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:09:18 by pshevche          #+#    #+#             */
/*   Updated: 2023/12/03 16:09:19 by pshevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45, target), _target(target) {
    std::srand(std::time(NULL));  // Seed for random number generator
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

const std::string &RobotomyRequestForm::getTarget() const {
    return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    validateExecution(executor);

    std::cout << "Bzzzz... Brrrr... " << _target << " has been robotomized!" << std::endl;

    // 50% chance of success
    if (std::rand() % 2 == 0) {
        std::cout << "Robotomy was successful!" << std::endl;
    } else {
        std::cout << "Robotomy failed." << std::endl;
    }
}
