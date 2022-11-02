#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() :
	Form("pardon","default", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target) : 
	Form(name, target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) :
	Form(src)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	this->Form::operator=(rhs);
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void PresidentialPardonForm::action(Bureaucrat const & executor) const
{
	try
	{
		this->Form::execute(executor);
	}
	catch(std::exception & e)
	{
		std::cerr << executor.getName() << " couldn't execute " << this->get_name() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->Form::get_target() << " is pardoned by Zaphod Beeblebrox." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */