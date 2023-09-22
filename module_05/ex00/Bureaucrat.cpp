#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else
        this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat & other)
{
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    this->grade = other.grade;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int     Bureaucrat::getGrade() const
{
    return this->grade;
}

void    Bureaucrat::increment()
{
    if(this->grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void    Bureaucrat::decrement()
{
    if (this->grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

std::ostream & operator<<(std::ostream & obj, Bureaucrat & input)
{
    obj << input.getName() << ", Bureaucrat grade " << input.getGrade();
    return (obj);
}
