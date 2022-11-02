

#include "Bureaucrat.hpp"

int main()
{
	try
	{
        Bureaucrat tar("tar",1);
        Bureaucrat mongo("mongo", 149);
		std::cout << tar << std::endl;
		std::cout << mongo << std::endl;
		tar.increment();
		mongo.decrement();
		std::cout << tar << std::endl;
		std::cout << mongo << std::endl;
		tar.increment();
		mongo.decrement();
		std::cout << tar << std::endl;
		std::cout << mongo << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}