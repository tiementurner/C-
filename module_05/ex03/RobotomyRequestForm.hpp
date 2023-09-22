#pragma once

# include "AForm.hpp"
# include <iostream>
# include <string>

class RobotomyRequestForm : public AForm
{

	public:

		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm( RobotomyRequestForm const & src );
		~RobotomyRequestForm();

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

		void	action(Bureaucrat const & executor) const;

	private:

};

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

