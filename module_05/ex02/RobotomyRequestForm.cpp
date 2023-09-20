#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm","default", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	AForm("RobotomyRequestForm", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) :
	AForm(src)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}


RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	this->AForm::operator=(rhs);
	return *this;
}


void RobotomyRequestForm::action(Bureaucrat const & executor) const
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
	std::cout << "*Drilling noises*" << std::endl;
	srand(time(NULL));
	rand();
	if (rand() < RAND_MAX / 2)
	{
		std::cout << this->AForm::get_target() << " Is robotomized." << std::endl;
		return ;
	}
	else
	{
		std::cout << "Drilling failed." << std::endl;
		return ;
	}
}
