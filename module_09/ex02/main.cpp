#include "PmergeMe.hpp"

void	error_and_exit(std::string error_msg)
{
	std::cout << "Error: " << error_msg << std::endl;
	exit(1);
}




int main(int ac, char **av)
{
	if (ac < 2)
		error_and_exit("Not enough arguments given");
	
	std::cout << "Before: ";
	
	std::list<int> ford_list;
	std::vector<int> ford_vector;
	for (int i = 1; i < ac; i++)
	{
		for (size_t j = 0; j < strlen(av[i]); j++)
		{
			if (!isalnum(av[i][j]))
				error_and_exit("One of the numbers is invalid (only positive integers please!)");
		}
		ford_vector.push_back(atoi(av[i]));
		ford_list.push_back(atoi(av[i]));
		std::cout << av[i] << " ";
	}
	std::cout << std::endl;

	clock_t start_list = clock();
	ford_johnson_list(ford_list);
	clock_t end_list = clock();
	
	
	clock_t start_vector = clock();
	ford_johnson_vector(ford_vector);
	clock_t end_vector = clock();

	
	std::cout << "After: ";
	for (auto x: ford_list)
		std::cout << x << " ";	
	std::cout << std::endl;
	
	std::cout << "time for std::list : " << double(end_list - start_list) << std::endl;
	std::cout << "time for std::vector : " << double(end_vector - start_vector) << std::endl;

	// for (std::list<int>::iterator i = ford_list.begin(); i != ford_list.end(); i++)
		// std::cout << *i << " ";

}