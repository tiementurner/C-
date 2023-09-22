#include "AForm.hpp"

AForm::AForm() : 
	target(""),
	name("default"), 
	exec_grade(150),
	sign_grade(150),
	_signed(false)
{
}

AForm::AForm(const std::string name, const int exec_grade, const int sign_grade) :
	name(name),
	exec_grade(exec_grade),
	sign_grade(sign_grade)

{
	if (exec_grade > 150 || sign_grade > 150)
		throw(AForm::GradeTooLowException());
	if (exec_grade < 1 || sign_grade < 1)
		throw(AForm::GradeTooHighException());
	this->_signed = false;
}

AForm::AForm(const std::string& name, const std::string& target, const int sign_grade, const int exec_grade)
	: 	target(target),
	 	name(name),
		exec_grade(exec_grade),
	   	sign_grade(sign_grade),
	  	_signed(false)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw AForm::GradeTooHighException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm & other) :
	name(other.name),
	exec_grade(other.exec_grade),
	sign_grade(other.sign_grade)
{
	this->_signed = other._signed;
}


AForm::~AForm()
{
}


AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_signed = rhs.get_signed();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o << "name = " << i.get_name() << std::endl
	  << "exec_grade = " << i.get_exec_grade() << std::endl
	  << "sign_grade = " << i.get_sign_grade() << std::endl
	  << "is signed = " << i.get_signed() << std::endl;
	return o;
}


void AForm::beSigned(const Bureaucrat& crat)
{
	if (this->_signed)
		throw(AForm::AFormAlreadySigned());
	if (crat.getGrade() <= this->sign_grade)
		this->_signed = true;
	else
		throw(AForm::GradeTooLowException());
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->get_signed())
		throw(AForm::AFormNotSignedException());
	if (executor.getGrade() > this->get_exec_grade())
		throw(AForm::GradeTooLowException());
}

std::string AForm::get_target() const
{
	return (this->target);
}

std::string AForm::get_name() const
{
    return (this->name);
}

int     AForm::get_exec_grade() const
{
    return (this->exec_grade);
}

int     AForm::get_sign_grade() const
{
    return (this->sign_grade);
}

bool     AForm::get_signed() const
{
    return (this->_signed);
}

