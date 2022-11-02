#pragma once

#include <string>
#include <iostream>

class Bureaucrat
{
    private:
        std::string const name;
        unsigned int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string const name, unsigned int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);

        std::string          getName() const;
        unsigned int         getGrade() const;
        void                 increment();
        void                 decrement();

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
