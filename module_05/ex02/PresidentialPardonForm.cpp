#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm","default", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
	AForm("PresidentialPardonForm", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) :
	AForm(src)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}


PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	this->AForm::operator=(rhs);
	return *this;
}


void PresidentialPardonForm::action(Bureaucrat const & executor) const
{
	try
	{
		this->AForm::execute(executor);
	}
	catch(std::exception & e)
	{
		std::cerr << executor.getName() << " couldn't execute " << this->get_name() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->AForm::get_target() << " is pardoned by Zaphod Beeblebrox." << std::endl;
}

