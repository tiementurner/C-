#include <algorithm>
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include "easyfind.hpp"
#include <iostream>
int main()
{
    //Arrays
    std::array<int, 6> int_array = {1,2,6,3,2,7};
    std::array<int, 6>::iterator array_result;
    
    print_seq_container(int_array);

    try{array_result = easyfind(int_array, 12);}
    catch(const std::invalid_argument &e){std::cout << e.what() << std::endl;}

    array_result = easyfind(int_array, 2);
    std::cout << "result : " << *array_result << std::endl;
    std::advance(array_result, 1);
    std::cout << "result after advancing one: " << *array_result << std::endl << std::endl;

    //Vectors
    std::vector<int> int_vector(10, 4);
    std::vector<int>::iterator vector_result;
    int_vector.push_back(2);

    print_seq_container(int_vector);

    try{vector_result = easyfind(int_vector, 12);}
    catch(const std::invalid_argument &e){std::cout << e.what() << std::endl;}

    vector_result = easyfind(int_vector, 2);
    std::cout << "result: " << *vector_result << std::endl;
    std::advance(vector_result, 1);
    std::cout <<  "result after advancing one: " << *vector_result << std::endl << std::endl;

    //Deque
    std::deque<int> int_deque(10, 5);
    std::deque<int>::iterator deque_result;
    int_deque.push_front(2);

    print_seq_container(int_deque);

    try{deque_result = easyfind(int_deque, 12);}
    catch(const std::invalid_argument &e){std::cout << e.what() << std::endl; }

    deque_result = easyfind(int_deque, 2);
    std::cout << "result: " << *deque_result << std::endl;
    std::advance(deque_result, 1);
    std::cout << "result after advancing one: " << *deque_result << std::endl << std::endl;

    //Forward list
    std::forward_list<int> int_forward_list(10, 6);
    std::forward_list<int>::iterator forward_list_result;
    int_forward_list.push_front(2);

    print_seq_container(int_forward_list);

    try{forward_list_result = easyfind(int_forward_list, 12);}
    catch(const std::invalid_argument &e){std::cout << e.what() << std::endl; }

    forward_list_result = easyfind(int_forward_list, 2);
    std::cout << "result: " << *forward_list_result << std::endl;
    std::advance(forward_list_result, 1);
    std::cout << "result after advancing one: " << *forward_list_result << std::endl << std::endl;

    //List
    std::list<int> int_list(10, 3);
    std::list<int>::iterator list_result;
    int_list.push_front(2);

    print_seq_container(int_list);

    try{list_result = easyfind(int_list, 12);}
    catch(const std::invalid_argument &e){std::cout << e.what() << std::endl; }
    list_result = easyfind(int_list, 2);
    std::cout << "result: " << *list_result << std::endl;
    std::advance(list_result, 1);
    std::cout << "result after advancing one: " << *list_result << std::endl << std::endl;
}