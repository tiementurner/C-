#pragma once


# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class Bureaucrat;

class Form
{

	public:

		Form();
		Form(const std::string& name, const std::string& target, const unsigned int sign_grade, const unsigned int exec_grade);
		Form(const std::string name, const unsigned int exec_grade, const unsigned sign_grade);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		std::string			 get_target() const;
		std::string          get_name() const;
        unsigned int         get_exec_grade()const;
		unsigned int		 get_sign_grade()const;
		bool				 get_signed()const;

		void				 beSigned(const Bureaucrat & crat);
		void				 execute(Bureaucrat const &executor) const;
		virtual	void		 action(Bureaucrat const &executor) const = 0;


		class GradeTooHighException : public std::exception 
		{
			public:
				const char * what() const throw()
				{
					return ("Grade too high.");
				}	
		};
		class FormNotSignedException : public std::exception 
		{
			public:
				const char * what() const throw()
				{
					return ("Form is not signed.");
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
		std::string 		const	target;
		std::string 		const	name;
		unsigned int		const	exec_grade;
		unsigned int 		const	sign_grade;
		bool 						_signed;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );
