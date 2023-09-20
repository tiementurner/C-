

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	// try
	// {
    //     Bureaucrat tar("tar",2);
    //     Bureaucrat mongo("mongo", 149);
	// 	std::cout << tar << std::endl;
	// 	std::cout << mongo << std::endl << std::endl;
	// 	std::cout << "increment tar and decrement mongo:" << std::endl;
	// 	tar.increment();
	// 	mongo.decrement();
	// 	std::cout << tar << std::endl;
	// 	std::cout << mongo << std::endl << std::endl;
	// 	std::cout << "increment tar and decrement mongo:" << std::endl;
	// 	//tar.increment();
	// 	mongo.decrement();
	// 	std::cout << tar << std::endl;
	// 	std::cout << mongo << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	// std::cout << "\n\n";

	// try{ Bureaucrat toohigh("toohigh", -1); }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// try{ Bureaucrat toolow("toolow", 151); }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// std::cout << "\n\n";


	try { Form tinyform("tiny", -1, -1); }
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try {Form hugeform("huge", 151, 151);}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n";

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
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}