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
	std::cout << std::endl << std::endl;

	clock_t start_list = clock();
	merge_insert_sort_list(ford_list);
	clock_t end_list = clock();
	
	
	clock_t start_vector = clock();
	merge_insert_sort_vector(ford_vector);
	clock_t end_vector = clock();

	
	std::cout << "After[vector]: ";
	for (std::vector<int>::iterator it = ford_vector.begin(); it != ford_vector.end(); it++)
		std::cout << *it << " ";	
	std::cout << std::endl;

	// // std::cout << "After[list]: ";
	// // for (std::list<int>::iterator it = ford_list.begin(); it != ford_list.end(); it++)
	// // 	std::cout << *it << " ";	
	// // std::cout << std::endl;
	
	// std::cout << "time for std::list : " << double(end_list - start_list)<< std::endl;
	// std::cout << "time for std::vector : " << double(end_vector - start_vector) << std::endl;

	// for (std::list<int>::iterator i = ford_list.begin(); i != ford_list.end(); i++)
		// std::cout << *i << " ";

	//NIET VERGETEN FLAGS TERUG TE ZETTEN

}