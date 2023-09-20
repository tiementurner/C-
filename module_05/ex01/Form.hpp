#pragma once


# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class Bureaucrat;

class Form
{

	public:

		Form();
		Form(const std::string name, const  int exec_grade, const int sign_grade);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		std::string          get_name() const;
        unsigned int         get_exec_grade()const;
		unsigned int		 get_sign_grade()const;
		bool				 get_signed()const;

		void				 beSigned(const Bureaucrat & crat);

		class GradeTooHighException : public std::exception 
		{
			public:
				const char * what() const throw()
				{
					return ("Grade too high.");
				}	
		};


		class GradeTooLowException : public std::exception 
		{
			public:
				const char * what() const throw()
				{
					return ("Grade too low.");
				}	
		};

		class FormAlreadySigned : public std::exception
		{
			public:
			const char * what() const throw()
			{
				return ("Form Already signed.");
			}
		};

	private:
		std::string const	name;
		int			const	exec_grade;
		int 		const	sign_grade;
		bool 				_signed;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );
