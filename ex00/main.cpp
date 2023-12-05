/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:47:25 by simao             #+#    #+#             */
/*   Updated: 2023/12/05 16:54:17 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat bur("Simao", 150);
    std::cout << bur.get_name() << std::endl;
    std::cout << bur.get_grade() << std::endl;

    std::cout << "--------------------" << std::endl;

    Bureaucrat other("Tomas", 1);
    std::cout << other.get_name() << std::endl;
    std::cout << other.get_grade() << std::endl;

    std::cout << "-----TO LOW------(151)---------" << std::endl;

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
        std::cout << other_bur.get_name() << std::endl;
        std::cout << other_bur.get_grade() << std::endl;
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    std::cout << "------DECREMENT--------------" << std::endl;

    try 
    {
        bur.dec_grade();
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << bur.get_grade() << std::endl;

    std::cout << "-------INCREMENT-------------" << std::endl;

    try 
    {
        bur.inc_grade();
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << bur.get_grade() << std::endl;

    std::cout << "--------INCREMENET------------" << std::endl;

    try 
    {
        other.inc_grade();
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << other.get_grade() << std::endl;

    std::cout << "-------DECREMENT-------------" << std::endl;

    try 
    {
        other.dec_grade();
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << other.get_grade() << std::endl;

    std::cout << "--------------------" << std::endl;

    std::cout << bur << std::endl;
    
    std::cout << "--------------------" << std::endl;
    
    return (0);
}
