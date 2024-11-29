#include "PmergeMe.hpp"


// Helper function to perform pairwise sorting

void pairwise_sort(std::list<int>& arr) {
    auto it = arr.begin();
    while (it != arr.end()) {
        auto next_it = std::next(it); 
        if (next_it == arr.end()) {
            break;
        }
        
        if (*it > *next_it) {
            std::swap(*it, *next_it); 
        
        std::advance(it, 2);
  		}
	}
}

std::list<int> generate_jacobsthal_sequence(int length) {
    std::list<int> jacobsthal = {1, 3};  
    
    while (jacobsthal.back() < length) {
        int last = jacobsthal.back();
        int second_last = *(--(--jacobsthal.end()));
        jacobsthal.push_back(last + 2 * second_last);
    }

    return jacobsthal;
}

void fill_paired_array(const std::list<int>& input, std::list<std::pair<int, int>>& paired_array) {
    std::list<int>::const_iterator it = input.begin();
    while (it != input.end()) {
        std::list<int>::const_iterator next_it = std::next(it);
        if (next_it == input.end()) break;
        paired_array.emplace_back(*it, *next_it);
        std::advance(it, 2);
    }
}


void sort_each_pair(std::list<std::pair<int, int>>& paired_array) {
    for (std::list<std::pair<int, int>>::iterator it = paired_array.begin(); it != paired_array.end(); ++it) {
        std::pair<int, int>& p = *it;

        if (p.first > p.second) {
            int temp = p.first;
            p.first = p.second;
            p.second = temp;
        }
    }
}

void sort_by_largest(std::list<std::pair<int, int>>& paired_array) {
    if (paired_array.size() <= 1) {
        return;
    }

    std::list<std::pair<int, int>>::iterator it = std::next(paired_array.begin());
    while (it != paired_array.end()) {
        std::pair<int, int> key = *it;
        std::list<std::pair<int, int>>::iterator j = it;
        
        while (j != paired_array.begin() && std::prev(j)->second > key.second) {
            --j;
        }
        if (j != it) {
            paired_array.erase(it);
            paired_array.insert(j, key);
        }

        it = std::next(j);
    }
}


int binary_search(const std::list<int>& S, int position, int value) {
    std::list<int>::const_iterator left = S.begin();
    std::list<int>::const_iterator right = std::next(S.begin(), position); // Change position to position (exclusive)

    while (left != right) {
        std::list<int>::const_iterator mid = std::next(left, std::distance(left, right) / 2);
        
        if (*mid == value) {
            return std::distance(S.begin(), mid);
        }
        else if (*mid < value) {
            left = std::next(mid);
        } else {
            right = mid;
        }
    }

    return std::distance(S.begin(), left);
}

void insert_pend(std::list<int>& S, int position, int value) {
    int insertIndex = binary_search(S, position, value);
    std::list<int>::iterator it = std::next(S.begin(), insertIndex);
    S.insert(it, value);
}

void merge_insert_sort_list(std::list<int>& arr) {
	
	std::list<std::pair<int, int>> paired_array;
	std::list<int> S;
	std::list<int> pend;
    
	if (arr.size() <= 1) 
		return;

	//determine odd or even
    bool isOdd = arr.size() % 2 != 0;
    int straggler = isOdd ? arr.back() : 0;
    if (isOdd) arr.pop_back();

	fill_paired_array(arr, paired_array);
	sort_each_pair(paired_array);
	sort_by_largest(paired_array);

	for (std::list<std::pair<int, int>>::const_iterator it = paired_array.begin(); it != paired_array.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;


	//make main chain 'S' and pending chain 'pend' to be inserted into S
	for (std::list<std::pair<int,int>>::iterator it = paired_array.begin(); it != paired_array.end(); it++)
		S.push_back(it->second);
	for (std::list<std::pair<int,int>>::iterator it = paired_array.begin(); it != paired_array.end(); it++)
		pend.push_back(it->first);


	S.insert(S.begin(), *pend.begin());

	std::list<int> jacobsthal = generate_jacobsthal_sequence(pend.size());
	
	for (std::list<int>::iterator it = std::next(jacobsthal.begin()); it != jacobsthal.end(); ++it) {
		int j = *it - 1;
		if (j >= (int)std::distance(pend.begin(), pend.end()))
			j = std::distance(pend.begin(), pend.end()) - 1;
		
		while (j > (*(std::prev(it)) - 1)) {
			std::list<int>::iterator pend_it = std::next(pend.begin(), j);
			insert_pend(S, (int)paired_array.size(), *pend_it);
			j--;
		}
	}

	insert_pend(S, S.size(), straggler);

	arr = S;
}
