#pragma once

#include <iostream>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctime>
#include <list>
#include <vector>
#include <algorithm>

void 	ford_johnson_list(std::list<int> &ford_list);

void	ford_johnson_vector(std::vector<int> &ford_vector);

void 	merge_insert_sort_vector(std::vector<int>& arr);