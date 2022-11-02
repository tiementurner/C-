#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() :
	Form("pardon","default", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target) : 
	Form(name, target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) :
	Form(src)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	this->Form::operator=(rhs);
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::action(Bureaucrat const & executor) const
{
	std::string string = "ASCII trees";
	try
	{
		this->Form::execute(executor);
	}
	catch(std::exception & e)
	{
		std::cerr << executor.getName() << " couldn't execute " << this->get_name() << " because " << e.what() << std::endl;
		return ;
	}
	std::ofstream file(this->get_target().append("_shrubbery"));

	if(file.is_open())
		file << string << std::endl;
	else
	{
		std::cout << "error opening file." << std::endl;
	}
	std::cout << "File created!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */