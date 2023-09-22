#pragma once


# include "AForm.hpp"
# include <iostream>
# include <string>
# include <fstream>

class ShrubberyCreationForm : public AForm
{

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm();

		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );

		void	action(Bureaucrat const & executor) const;
	
	private:

};

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

