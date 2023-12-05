/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:54:46 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/04 23:29:29 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try 
    {
        Bureaucrat bob("Bob", 5);
        Bureaucrat jim("Jim", 150);
        ShrubberyCreationForm shrubForm("Home");
        RobotomyRequestForm robotForm("Bender");
        PresidentialPardonForm pardonForm("John Doe");

        std::cout << bob << std::endl;
        std::cout << jim << std::endl;
        std::cout << shrubForm << std::endl;
        std::cout << robotForm << std::endl;
        std::cout << pardonForm << std::endl;

        bob.sign_form(shrubForm);
        bob.execute_form(shrubForm);
        
        bob.sign_form(robotForm);
        bob.execute_form(robotForm);
        
        bob.sign_form(pardonForm);
        bob.execute_form(pardonForm);

        jim.sign_form(shrubForm);
        jim.execute_form(shrubForm);
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
