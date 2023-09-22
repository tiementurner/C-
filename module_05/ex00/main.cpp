
#include "Bureaucrat.hpp"

int main()
{
	try
	{
        Bureaucrat tar("tar",2);
        Bureaucrat mongo("mongo", 149);
		std::cout << tar << std::endl;
		std::cout << mongo << std::endl << std::endl;
		std::cout << "increment tar and decrement mongo:" << std::endl;
		tar.increment();
		mongo.decrement();
		std::cout << tar << std::endl;
		std::cout << mongo << std::endl << std::endl;
		std::cout << "increment tar and decrement mongo:" << std::endl;
		//tar.increment();
		mongo.decrement();
		std::cout << tar << std::endl;
		std::cout << mongo << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n";

	try{ Bureaucrat toohigh("toohigh", -1); }
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try{ Bureaucrat toolow("toolow", 151); }
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}