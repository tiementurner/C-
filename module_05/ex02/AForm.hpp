#pragma once


# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{

	public:

		AForm();
		AForm(const std::string& name, const std::string& target, const int sign_grade, const int exec_grade);
		AForm(const std::string name, const int exec_grade, const int sign_grade);
		AForm( AForm const & src );
		~AForm();

		AForm &		operator=( AForm const & rhs );

		std::string			 get_target() const;
		std::string          get_name() const;
        int         		 get_exec_grade()const;
		int		 		     get_sign_grade()const;
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
		class AFormNotSignedException : public std::exception 
		{
			public:
				const char * what() const throw()
				{
					return ("AForm is not signed.");
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
		class AFormAlreadySigned : public std::exception
		{
			public:
			const char * what() const throw()
			{
				return ("AForm Already signed.");
			}
		};
		private:
		std::string 		const	target;
		std::string 		const	name;
		int					const	exec_grade;
		int 				const	sign_grade;
		bool 						_signed;

};

std::ostream &			operator<<( std::ostream & o, AForm const & i );
