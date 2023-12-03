/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:27:02 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/03 17:01:17 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string.h>

class Form 
{
    public:
        Form();
        ~Form();
    private:
        bool form_signed;
        std::string const name;
        int const grade;
};

#endif