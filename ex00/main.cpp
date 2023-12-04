/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:47:25 by simao             #+#    #+#             */
/*   Updated: 2023/12/04 14:01:05 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat bur("Simao", 150);
    std::cout << bur.getName() << std::endl;
    std::cout << bur.getGrade() << std::endl;

    std::cout << "--------------------" << std::endl;

    Bureaucrat other("Tomas", 1);
    std::cout << other.getName() << std::endl;
    std::cout << other.getGrade() << std::endl;

    std::cout << "-----TO LOW------(150)---------" << std::endl;

    try 
    {
        Bureaucrat other_bur("Ramos", 151);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    std::cout << "------TO HIGH-----(0)---------" << std::endl;

    try 
    {
        Bureaucrat other_bur("Rita", 0);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    std::cout << "----------OK----------" << std::endl;

    try 
    {
        Bureaucrat other_bur("Daniela", 5);
        std::cout << other_bur.getName() << std::endl;
        std::cout << other_bur.getGrade() << std::endl;
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    std::cout << "------DECREMENT--------------" << std::endl;

    try 
    {
        bur.decGrade();
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << bur.getGrade() << std::endl;

    std::cout << "-------INCREMENT-------------" << std::endl;

    try 
    {
        bur.incGrade();
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << bur.getGrade() << std::endl;

    std::cout << "--------INCREMENET------------" << std::endl;

    try 
    {
        other.incGrade();
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << other.getGrade() << std::endl;

    std::cout << "-------DECREMENT-------------" << std::endl;

    try 
    {
        other.decGrade();
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << other.getGrade() << std::endl;

    std::cout << "--------------------" << std::endl;

    std::cout << bur << std::endl;
    
    std::cout << "--------------------" << std::endl;
    
    return (0);
}
