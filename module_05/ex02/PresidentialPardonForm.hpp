#pragma once

# include "AForm.hpp"
# include <iostream>
# include <string>

class PresidentialPardonForm : public AForm
{

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & src );
		~PresidentialPardonForm();

		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );

		void	action(Bureaucrat const & executor) const;

	private:

};

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i );
