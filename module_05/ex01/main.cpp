

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
        Bureaucrat tar("tar", 42);
		Form lilform("lilform", 150, 150);
		Form bigform("bigform", 1, 1);
		std::cout << lilform << std::endl;
		tar.signForm(lilform);std::cout << std::endl;
		tar.signForm(lilform);std::cout << std::endl;
		std::cout << lilform << std::endl;
		std::cout << bigform << std::endl;
		tar.signForm(bigform);std::cout << std::endl;
		std::cout << bigform << std::endl;
		for(int i = 0; i < 41 ; i++)
			tar.increment();
		tar.signForm(bigform);std::cout << std::endl;
		std::cout << bigform << std::endl;

		Form tinyform("tiny", -1, -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}