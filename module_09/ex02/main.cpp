#include <iostream>
#include <list>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <chrono>

void	error_and_exit(std::string error_msg)
{
	std::cout << "Error: " << error_msg << std::endl;
	exit(1);
}

void	merge_insert(std::list<int> &ford_list, std::list<int> &left_side, std::list<int> &right_side)
{
	std::cout << "in merge insert: " << reinterpret_cast<void *>(&ford_list) << std::endl;
	for(std::list<int>::iterator it = ford_list.begin(); it != ford_list.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;

	std::cout << "left side: " ;
	for(std::list<int>::iterator it = left_side.begin(); it != left_side.end(); it++)
		std::cout << *it << " ";

	std::cout << "right side: " ;
	for(std::list<int>::iterator it = right_side.begin(); it != right_side.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;


	std::list<int>::iterator iterator_left = left_side.begin();
	std::list<int>::iterator iterator_right = right_side.begin();
	std::list<int>::iterator iterator_main = ford_list.begin();

   while (iterator_left != left_side.end() && iterator_right != right_side.end())
    {
        if (*iterator_left < *iterator_right)
		{
            *iterator_main = *iterator_left;
			iterator_left++;
		}
        else
		{
            *iterator_main = *iterator_right;
			iterator_right++;
		}
        iterator_main++;
    }
    while (iterator_left != left_side.end())
    {
        *iterator_main = *iterator_left;
        iterator_left++;
        iterator_main++;
    }
    while (iterator_right != right_side.end())
    {
        *iterator_main = *iterator_right;
        iterator_right++;
        iterator_main++;
    }
}



void 	ford_johnson(std::list<int> &ford_list)
{
	std::cout << "in ford johnson: " << reinterpret_cast<void *>(&ford_list) << std::endl;
	for (auto x : ford_list)
		std::cout << x << " ";
	std::cout << std::endl;

	std::list<int> temp_ford_list = ford_list;

	if (ford_list.size() > 1)
	{
		std::list<int> left_side;
		std::list<int> right_side;

		int middle = temp_ford_list.size() / 2;
		std::list<int>::iterator it_middle = temp_ford_list.begin();
		for (int i = 0; i < middle; i++)
			it_middle++;
		left_side.splice(left_side.begin(), temp_ford_list, temp_ford_list.begin(), it_middle);
		// for(std::list<int>::iterator i = left_side.begin(); i != left_side.end(); ++i)
		// 	std::cout << *i << std::endl;
		
		right_side.splice(right_side.begin(), temp_ford_list, it_middle, temp_ford_list.end());
		// for(std::list<int>::iterator i = right_side.begin(); i != right_side.end(); ++i)
			// std::cout << *i << std::endl;

		ford_johnson(left_side);
		ford_johnson(right_side);

		merge_insert(ford_list, left_side, right_side);
	}

}


int main(int ac, char **av)
{
	if (ac < 2)
		error_and_exit("Not enough arguments given");
	std::list<int> ford_list;
	for (int i = 1; i < ac; i++)
	{
		for (size_t j = 0; j < strlen(av[i]); j++)
		{
			if (!isalnum(av[i][j]))
				error_and_exit("One of the numbers is invalid (only positive integers please!)");
		}
		ford_list.push_back(atoi(av[i]));
	}

	time_t start, end;
	time(&start);
	ford_johnson(ford_list);
	time(&end);
	std::cout << "time for std::list : " << double(end - start);

	for (auto x: ford_list)
		std::cout << x << " ";
	// for (std::list<int>::iterator i = ford_list.begin(); i != ford_list.end(); i++)
		// std::cout << *i << " ";

	
	
}