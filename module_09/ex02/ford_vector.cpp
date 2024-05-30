#include "PmergeMe.hpp"

static std::vector<int> slice(std::vector<int>& arr, int X, int Y)
{
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y;
 
    std::vector<int> result(Y - X);
 
    copy(start, end, result.begin());

    return result;
}

static void merge_insert_vector(std::vector<int> &ford_vector, std::vector<int> &left_side, std::vector<int> &right_side)
{
	std::vector<int>::iterator iterator_left = left_side.begin();
	std::vector<int>::iterator iterator_right = right_side.begin();
	std::vector<int>::iterator iterator_main = ford_vector.begin();

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

void	ford_johnson_vector(std::vector<int> &ford_vector)
{

	if (ford_vector.size() > 1)
	{
		std::vector<int> left_side;
		std::vector<int> right_side;

		int middle = ford_vector.size() / 2;
		
		left_side = slice(ford_vector, 0, middle);
		right_side = slice(ford_vector, middle, ford_vector.size());

		ford_johnson_vector(left_side);
		ford_johnson_vector(right_side);
	
		merge_insert_vector(ford_vector, left_side, right_side);
	}
}