#include "PmergeMe.hpp"


// Helper function to perform pairwise sorting
void pairwise_sort(std::vector<int>& arr) {
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1]) {
            std::swap(arr[i], arr[i + 1]);
        }
    }
}

std::vector<int> generate_jacobsthal_sequence(int length) {
    std::vector<int> jacobsthal = {1, 3};
    while (jacobsthal.back() < length) {
        jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2]);
		//std::cout << jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2] << std::endl;
    }
    //jacobsthal.erase(jacobsthal.begin());

    return jacobsthal;
}

void fill_paired_array(const std::vector<int>& input, std::vector<std::pair<int, int>>& paired_array) {
    // Iterate through the input vector in steps of 2
    for (size_t i = 0; i < input.size(); i += 2) {
        // Create a pair with the current and the next element
        paired_array.emplace_back(input[i], input[i + 1]);
    }
}

void sort_each_pair(std::vector<std::pair<int, int>>& paired_array) {
    for (size_t i = 0; i < paired_array.size(); ++i) {
        std::pair<int, int>& p = paired_array[i]; // Explicitly define the pair

        // Sort the pair using a temporary variable
        if (p.first > p.second) {
            int temp = p.first; // Store the first value in a temporary variable
            p.first = p.second; // Assign the second value to the first
            p.second = temp; // Assign the temporary value to the second
        }
    }
}

void sort_by_largest(std::vector<std::pair<int, int>>& paired_array) {
    int n = paired_array.size();
    
    for (int i = 1; i < n; i++) {
        std::pair<int, int> key = paired_array[i];
        int j = i - 1;

        while (j >= 0 && paired_array[j].second > key.second) {
            paired_array[j + 1] = paired_array[j];
            j--;
        }
        paired_array[j + 1] = key;
    }
}

int binary_search(const std::vector<int>& S, int position, int value) {
    int left = 0;
    int right = position - 1;   

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (S[mid] == value) {
            return mid;
        }
        else if (S[mid] < value) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    return left;
}

void insert_pend(std::vector<int>& S, int position, int value) {
    int insertIndex = binary_search(S, position, value);
    
    S.insert(S.begin() + insertIndex, value);
}

void merge_insert_sort_vector(std::vector<int>& arr) {
	
	std::vector<std::pair<int, int>> paired_array;
	std::vector<int> S;
	std::vector<int> pend;
    
	if (arr.size() <= 1) return;

    // Determine if the length is odd or even
    bool isOdd = arr.size() % 2 != 0;
    int straggler = isOdd ? arr.back() : 0;
    if (isOdd) arr.pop_back();


	fill_paired_array(arr, paired_array);
	sort_each_pair(paired_array);
	sort_by_largest(paired_array);

	for (size_t i = 0; i < paired_array.size(); i++)
		S.push_back(paired_array[i].second);

	for (size_t i = 0; i < paired_array.size(); i++)
		pend.push_back(paired_array[i].first);

	S.insert(S.begin(), pend[0]);

	std::vector<int> jacobsthal = generate_jacobsthal_sequence(pend.size());

	for (size_t i = 1; i < jacobsthal.size(); i++) {
		int j = jacobsthal[i] - 1;
		if (j >= (int)pend.size())
			j = pend.size() - 1;
		// std::cout << "j before while: " << j << std::endl;
		// std::cout << "pend.size: " << pend.size() << std::endl;
		
		while (j > (jacobsthal[i - 1] - 1)) {
			insert_pend(S, (int)paired_array.size(), pend[j]);
			//std::cout << "j:" << j << "  pend[j]: " << pend[j] << std::endl;
			j--;
		}
		std::cout << std::endl;
	}

	insert_pend(S, S.size(), straggler);

	// for (auto it : S)
	// 	std::cout << it << " ";
	// std::cout << std::endl;

    // for (const auto& p : paired_array) {
    //     std::cout << "(" << p.first << ", " << p.second << ") ";
    // }
    // std::cout << std::endl;

	arr = S;
}
