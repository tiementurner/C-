#include "Form.hpp"

Form::Form() : 
	name("default"), 
	exec_grade(150),
	sign_grade(150),
	_signed(false)
{
}

Form::Form(const std::string name, const int exec_grade, const int sign_grade) :
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

Form::Form(const Form & other) :
	name(other.name),
	exec_grade(other.exec_grade),
	sign_grade(other.sign_grade)
{
	this->_signed = other._signed;
}


Form::~Form()
{
}


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

void Form::beSigned(const Bureaucrat& crat)
{
	if (this->_signed)
		throw(Form::FormAlreadySigned());
	if (crat.getGrade() <= this->sign_grade)
		this->_signed = true;
	else
		throw(Form::GradeTooLowException());
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

