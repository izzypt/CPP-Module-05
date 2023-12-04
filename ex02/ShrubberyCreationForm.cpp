/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:08:10 by pshevche          #+#    #+#             */
/*   Updated: 2023/12/04 22:41:18 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137, target), _target(target)
{
    std::cout << "ShrubberyCreationForm " << _target << " constructed." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) 
{
    std::cout << "ShrubberyCreationForm " << _target << " copy constructed." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm " << _target << " destructed." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
        std::cout << "ShrubberyCreationForm " << _target << " copy assigned." << std::endl;
    }
    return *this;
}

const std::string &ShrubberyCreationForm::getTarget() const
{
    return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    validateExecution(executor);
    std::cout << "Executing ShrubberyCreationForm for " << _target << " by " << executor.get_name() << std::endl;
    
    std::ofstream outFile((_target + "_shrubbery").c_str());
    if (!outFile) {
        throw std::runtime_error("Unable to create file");
    }

    std::string tree = "    ###\n"
                       "   #o###\n"
                       " #####o###\n"
                       "#o#\\#|#/###\n"
                       " ###\\|/#o#\n"
                       "  # }|{  #\n"
                       "    }|{\n";

    outFile << tree;
    std::cout << tree;

    outFile.close();

    std::cout << "ShrubberyCreationForm executed successfully. ASCII tree written to " << _target + "_shrubbery" << std::endl;
}
