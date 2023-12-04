/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:30:47 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/04 19:30:41 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat cLuis("Luis", 30);
    Form form("FORMA", 5, 10);
    Form other_form("OTHER_FORM", 35, 10);

    std::cout << "------SHOW FORM--------------" << std::endl;

    std::cout << form.get_grade_to_execute() << std::endl;
    std::cout << form.get_grade_to_sign() << std::endl;
    std::cout << form.get_name() << std::endl;

    std::cout << form << std::endl;

    std::cout << "--------------------" << std::endl;

    try
    {
        form.beSigned(cLuis);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << form.get_signed() << std::endl;

    std::cout << "--------------------" << std::endl;

    try
    {
        other_form.beSigned(cLuis);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << other_form.get_signed() << std::endl;

    std::cout << "-------TRY LOW-------------" << std::endl;

    try 
    {
        Form try_form("TRY", 1, 151);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    std::cout << "--------------------" << std::endl;

    try 
    {
        Form try_form("TRY", 1, 149);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    std::cout << "-------TRY HIGH-------------" << std::endl;

    try 
    {
        Form try_form("TRY", -1, 149);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    std::cout << "--------------------" << std::endl;
    
    return (0);
}