#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() :
	Form("pardon","default", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target) : 
	Form(name, target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) :
	Form(src)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	this->Form::operator=(rhs);
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::action(Bureaucrat const & executor) const
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
	std::cout << "*Drilling noises*" << std::endl;
	srand(time(NULL));
	rand();
	if (rand() < RAND_MAX / 2)
	{
		std::cout << this->Form::get_target() << " Is robotomized." << std::endl;
		return ;
	}
	else
	{
		std::cout << "Drilling failed." << std::endl;
		return ;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */