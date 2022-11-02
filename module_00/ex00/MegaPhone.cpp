#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	for(int j = 1; j < argc; ++j)
		for(int i = 0; i < strlen(argv[j]); i++)
			putchar(toupper(argv[j][i]));
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << "\n";
}
