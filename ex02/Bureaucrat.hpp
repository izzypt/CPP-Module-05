#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

/* LIbraries */
#include <iostream>
#include <string.h>

/* Classes */
class Bureaucrat 
{
  
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &bureaucrat);
        Bureaucrat& operator=(const Bureaucrat &bureaucrat);
        std::string get_name() const;
        int get_grade() const;
        void inc_grade();
        void dec_grade();
        void sign_form(const bool sign, const std::string &form_name) const;
        void execute_form(AForm const & form);

    private:
        std::string name;
        int grade;
};


class GradeTooHighException : public std::exception 
{
    public:
            virtual const char* what() const throw() 
            {
                	return ("\e[0;38;5;9mForm Exception: Grade Too High\n\e[0m");
            }
};

class GradeTooLowException : public std::exception 
{
    public:
            virtual const char* what() const throw() 
            {
                			return ("\e[0;38;5;9mForm Exception: Grade Too Low\n\e[0m");
		
            }
};

std::ostream& operator<<(std::ostream &ost, Bureaucrat const &bur);

#endif