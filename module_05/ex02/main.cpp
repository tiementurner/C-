#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
	std::string target = "tar";
    Bureaucrat tar("tar", 42);
	PresidentialPardonForm ppf(target);
	
	tar.signForm(ppf);
	ppf.action(tar);

	for(int i = 0; i < 17 ; i++)
		tar.increment();
	std::cout << tar << std::endl;
	tar.signForm(ppf);
	tar.executeForm(ppf);

	for(int i = 0; i < 20 ; i++)
		tar.increment();
	std::cout << tar << std::endl;
	tar.signForm(ppf);
	tar.executeForm(ppf);
	std::cout<< std::endl << std::endl;
	///////////////////////

	
	Bureaucrat crazyman("crazyman", 73);
	RobotomyRequestForm rrf(crazyman.getName());

	crazyman.signForm(rrf);
	rrf.action(crazyman);

	crazyman.increment();
	std::cout << crazyman << std::endl;
	crazyman.signForm(rrf);
	crazyman.executeForm(rrf);

	for(int i = 0; i < 27 ; i++)
		crazyman.increment();
	std::cout << crazyman << std::endl;
	crazyman.signForm(rrf);
	crazyman.executeForm(rrf);
	std::cout<< std::endl << std::endl;
	//////////////////////////

	
	Bureaucrat normalman("normalman", 146);
	ShrubberyCreationForm scf(normalman.getName());

	normalman.signForm(scf);
	scf.action(normalman);

	normalman.increment();
	std::cout << normalman << std::endl;
	normalman.signForm(scf);
	normalman.executeForm(scf);

	for(int i = 0; i < 27 ; i++)
		normalman.increment();
	std::cout << normalman << std::endl;
	normalman.signForm(scf);
	normalman.executeForm(scf);
}