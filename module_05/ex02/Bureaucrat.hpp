#pragma once

#include "AForm.hpp"

#include <string>
#include <iostream>

class AForm;

class Bureaucrat
{
    private:
        std::string const name;
        int               grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string const name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);

        std::string          getName() const;
        int                  getGrade() const;
        void                 increment();
        void                 decrement();

        void                 signForm(AForm & form);
        void                 executeForm(AForm const &form);

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return ("Grade too high");
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return ("Grade too low");
                }
        };
};

std::ostream & operator<<(std::ostream & obj, Bureaucrat & input);
