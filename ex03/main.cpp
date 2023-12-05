/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshevche <pshevche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:09:05 by pshevche          #+#    #+#             */
/*   Updated: 2023/12/03 16:09:06 by pshevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        // Create a Bureaucrat with a high grade
        Bureaucrat highRankedBureaucrat("John", 1);
        std::cout << highRankedBureaucrat << std::endl;

        // Create an Intern
        Intern someRandomIntern;
        
        // Intern creates a ShrubberyCreationForm
        AForm* shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "Garden");
        if (shrubberyForm) {
            // Bureaucrat signs and executes the form
            highRankedBureaucrat.signForm(*shrubberyForm);
            highRankedBureaucrat.executeForm(*shrubberyForm);
            delete shrubberyForm;
        }
        
        // Intern creates a RobotomyRequestForm
        AForm* robotomyForm = someRandomIntern.makeForm("robotomy request", "Bender");
        if (robotomyForm) {
            // Bureaucrat signs and executes the form
            highRankedBureaucrat.signForm(*robotomyForm);
            highRankedBureaucrat.executeForm(*robotomyForm);
            delete robotomyForm;
        }
        
        // Intern creates a PresidentialPardonForm
        AForm* pardonForm = someRandomIntern.makeForm("presidential pardon", "Alice");
        if (pardonForm) {
            // Bureaucrat signs and executes the form
            highRankedBureaucrat.signForm(*pardonForm);
            highRankedBureaucrat.executeForm(*pardonForm);
            delete pardonForm;
        }
        
        // Try to create a form with an unknown name
        AForm* unknownForm = someRandomIntern.makeForm("unknown form", "Target");
        if (unknownForm) {
            // This block should not be executed
            delete unknownForm;
        }

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
