#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

/* LIbraries */
#include <iostream>
#include <string.h>

/* Classes */
class Bureaucrat
{
    protected:
        std::string const name;
    public:
        /* Constructors */
        Bureaucrat(void);
        Bureaucrat(Bureaucrat const &other);
        ~Bureaucrat(void);
        /* Operator Overloading */
        Bureaucrat& operator=(Bureaucrat const& other);
        /* Member Functions */
};

#endif