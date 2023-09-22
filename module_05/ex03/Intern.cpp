#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	*this = src;
}

Intern::~Intern()
{
}

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}


AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm* form = NULL;
	std::string names[] = {"robotomy request",
						"presidential pardon",
						"shrubbery creation"};
	int i = 0;
	while (i < 3 && names[i] != name)
		i++;
	switch(i)
	{
		case 0:
			form = new RobotomyRequestForm(target);
			break ;
		case 1:
			form = new PresidentialPardonForm(target);
			break;
		case 2:
			form = new ShrubberyCreationForm(target);
			break ;
		case 3:
			std::cout << "Intern couldn't create form." << std::endl;
			return (NULL);
	}

	std::cout << "Intern creates " << name << std::endl;
	return (form);
}
