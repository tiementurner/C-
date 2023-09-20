#include "ShrubberyCreationForm.hpp"



ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm","default", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
	AForm("ShrubberyCreationForm", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) :
	AForm(src)
{
}



ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	this->AForm::operator=(rhs);
	return *this;
}


void ShrubberyCreationForm::action(Bureaucrat const & executor) const
{
	std::string string = "ASCII trees";
	try
	{
		this->AForm::execute(executor);
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
