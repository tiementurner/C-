#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : 
	target(""),
	name("default"), 
	exec_grade(150),
	sign_grade(150),
	_signed(false)
{
}

Form::Form(const std::string name, const unsigned int exec_grade, const unsigned sign_grade) :
	name(name),
	exec_grade(exec_grade),
	sign_grade(sign_grade)

{
	if (exec_grade > 150 || sign_grade > 150)
		throw(Form::GradeTooLowException());
	if (exec_grade < 1 || sign_grade < 1)
		throw(Form::GradeTooHighException());
	this->_signed = false;
}

Form::Form(const std::string& name, const std::string& target, const unsigned int sign_grade, const unsigned int exec_grade)
	: 	target(target),
	 	name(name),
		exec_grade(exec_grade),
	   	sign_grade(sign_grade),
	  	_signed(false)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form & other) :
	name(other.name),
	exec_grade(other.exec_grade),
	sign_grade(other.sign_grade)
{
	this->_signed = other._signed;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_signed = rhs.get_signed();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "name = " << i.get_name() << std::endl
	  << "exec_grade = " << i.get_exec_grade() << std::endl
	  << "sign_grade = " << i.get_sign_grade() << std::endl
	  << "is signed = " << i.get_signed() << std::endl;
	return o;
}


/*
**
 --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(const Bureaucrat& crat)
{
	if (this->_signed)
		throw(Form::FormAlreadySigned());
	if (crat.getGrade() <= this->sign_grade)
		this->_signed = true;
	else
		throw(Form::GradeTooLowException());
}

void Form::execute(Bureaucrat const & executor) const
{
	if (!this->get_signed())
		throw(Form::FormNotSignedException());
	if (executor.getGrade() > this->get_exec_grade())
		throw(Form::GradeTooLowException());
}

std::string Form::get_target() const
{
	return (this->target);
}

std::string Form::get_name() const
{
    return (this->name);
}

unsigned int     Form::get_exec_grade() const
{
    return (this->exec_grade);
}

unsigned int     Form::get_sign_grade() const
{
    return (this->sign_grade);
}

bool     Form::get_signed() const
{
    return (this->_signed);
}

