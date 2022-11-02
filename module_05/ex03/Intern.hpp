#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
# include <iostream>
# include <string>

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );

		Form* makeForm(std::string name, std::string target);

	private:

};


#endif /* ********************************************************** INTERN_H */