#include "MutantStack.hpp"
#include <list>
int main()
{
    MutantStack<int> mstack;
    MutantStack<int> mstack2;
    

    std::cout << "empty : " << mstack.empty() << std::endl;
    
    std::cout << "push(1)" << std::endl; 
    mstack.push(1);
    std::cout << "mstack.top(): "<< mstack.top() << std::endl;
    std::cout << "empty : " << mstack.empty() << std::endl;
    std::cout << "size : " << mstack.size() << std::endl;
    std::cout << "push(2)" << std::endl; 
    mstack.push(2);
    std::cout << "size : " << mstack.size() << std::endl << std::endl;

    std::cout << "copy assignment: " << std::endl;
    mstack2 = mstack;
    std::cout << "empty2 : " << mstack2.empty() << std::endl;
    mstack2.push(1);
	std::cout << "mstack2.top(): "<< mstack2.top() << std::endl;
    std::cout << "empty2 : " << mstack2.empty() << std::endl;
    std::cout << "size2 : " << mstack2.size() << std::endl;
    mstack2.push(2);
    std::cout << "size2 : " << mstack2.size() << std::endl;

    MutantStack<int>::iterator it;
    it = mstack.begin();

	std::cout << "test iterators on size(100) mstack: " << std::endl;
    for(int i = 3; i < 100 ; i++)
        mstack.push(i);
    for(; it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl;


	std::cout << "test iterators on size(100) mstack with underlying vector container: " << std::endl;
    MutantStack<int, std::vector<int> > vectorstack;
    MutantStack<int, std::vector<int> >::iterator it_2;
    for(int i = 0; i < 100 ; i++)
        vectorstack.push(i + 100);
    for(it_2 = vectorstack.begin(); it_2 != vectorstack.end(); ++it_2)
        std::cout << *it_2 << " ";
    std::cout << std::endl << std::endl;


	std::cout << "test iterators on size(100) mstack with underlying list container: " << std::endl;
    MutantStack<int, std::list<int> > liststack;
    MutantStack<int, std::list<int> >::iterator it_3;
    for(int i = 0; i < 100 ; i++)
        liststack.push(i + 200);
    for(it_3 = liststack.begin(); it_3 != liststack.end(); ++it_3)
        std::cout << *it_3 << " ";
    std::cout << std::endl << std::endl;


	std::cout << "same test with std::list<int>" << std::endl;

    std::list<int> test_list;
    std::list<int> test_list2;
    

    std::cout << "empty : " << test_list.empty() << std::endl;
    
    std::cout << "push_back(1)" << std::endl; 
    test_list.push_back(1);
    std::cout << "test_list.top(): "<< test_list.back() << std::endl;
    std::cout << "empty : " << test_list.empty() << std::endl;
    std::cout << "size : " << test_list.size() << std::endl;
    std::cout << "push_back(2)" << std::endl; 
    test_list.push_back(2);
    std::cout << "size : " << test_list.size() << std::endl << std::endl;

    std::cout << "copy assignment: " << std::endl;
    test_list2 = test_list;
    std::cout << "empty : " << test_list2.empty() << std::endl;
    test_list2.push_back(1);
    std::cout << test_list2.back() << std::endl;
    std::cout << "empty : " << test_list2.empty() << std::endl;
    std::cout << "size : " << test_list2.size() << std::endl;
    test_list2.push_back(2);
    std::cout << "size : " << test_list2.size() << std::endl;

    std::list<int>::iterator list_it;
    list_it = test_list.begin();

	std::cout << "test iterators on size(100) list: " << std::endl;
    for(int i = 3; i < 100 ; i++)
        test_list.push_back(i);
    for(; list_it != test_list.end(); ++list_it)
        std::cout << *list_it << " ";
    std::cout << std::endl << std::endl;

	MutantStack<std::string> string_mstack;
	
	std::cout << "mstack tests with string as type: " << std::endl;
	
	std::cout << "empty : " << string_mstack.empty() << std::endl;
    std::cout << "push(1)" << std::endl; 
    string_mstack.push("Hallo");
    std::cout << "string_mstack.top(): "<< string_mstack.top() << std::endl;
    std::cout << "empty : " << string_mstack.empty() << std::endl;
    std::cout << "size : " << string_mstack.size() << std::endl;
    std::cout << "push(2)" << std::endl; 
    string_mstack.push("Doei");
    std::cout << "string_mstack.top(): "<< string_mstack.top() << std::endl;
    std::cout << "size : " << string_mstack.size() << std::endl << std::endl;
}