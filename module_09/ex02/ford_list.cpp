#include "PmergeMe.hpp"


static void	merge_insert_list(std::list<int> &ford_list, std::list<int> &left_side, std::list<int> &right_side)
{
	//std::cout << "in merge insert: " << reinterpret_cast<void *>(&ford_list) << std::endl;
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



void 	ford_johnson_list(std::list<int> &ford_list)
{


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
		right_side.splice(right_side.begin(), temp_ford_list, it_middle, temp_ford_list.end());

		ford_johnson_list(left_side);
		ford_johnson_list(right_side);

		merge_insert_list(ford_list, left_side, right_side);
	}

}