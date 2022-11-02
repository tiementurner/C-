#include <iostream>
#include <string>

// int main()
// {
// 	std::string var = "HI THIS IS BRAIN";
// 	std::string *stringPTR = &var;
// 	std::string &stringREF = var;

// 	std::cout << &var << std::endl;
// 	std::cout << &stringPTR << std::endl;
// 	std::cout << &stringREF << std::endl;

// 	std::cout << var << std::endl;
// 	std::cout << *stringPTR << std::endl;
// 	std::cout << stringREF << std::endl;
// }

void swap_nums(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = NULL;
	int b = 1;

	swap_nums(a,b);
	std::cout << a << b << std::endl;
}