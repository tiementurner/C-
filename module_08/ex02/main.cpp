#include "MutantStack.hpp"

int main()
{
    // MutantStack<int> mstack;
    // MutantStack<int> mstack2;
    

    // std::cout << "empty : " << mstack.empty() << std::endl;
    
    // std::cout << "push(1)" << std::endl; 
    // mstack.push(1);
    // std::cout << "mstack.top(): "<< mstack.top() << std::endl;
    // std::cout << "empty : " << mstack.empty() << std::endl;
    // std::cout << "size : " << mstack.size() << std::endl;
    // std::cout << "push(2)" << std::endl; 
    // mstack.push(2);
    // std::cout << "size : " << mstack.size() << std::endl << std::endl;

    // std::cout << "copy assignment: " << std::endl;
    // mstack2 = mstack;
    // std::cout << "empty : " << mstack2.empty() << std::endl;
    // mstack2.push(1);
    // std::cout << mstack2.top() << std::endl;
    // std::cout << "empty : " << mstack2.empty() << std::endl;
    // std::cout << "size : " << mstack2.size() << std::endl;
    // mstack2.push(2);
    // std::cout << "size : " << mstack2.size() << std::endl;

    // MutantStack<int>::iterator it;
    // it = mstack.begin();

    // for(int i = 3; i < 100 ; i++)
    //     mstack.push(i);
    // for(; it != mstack.end(); ++it)
    //     std::cout << *it << " ";
    // std::cout << std::endl << std::endl;


    MutantStack<int, std::vector<int> > vectorstack;
    MutantStack<int, std::vector<int> >::iterator it_2;
    for(int i = 0; i < 100 ; i++)
        vectorstack.push(i + 100);
    for(it_2 = vectorstack.begin(); it_2 != vectorstack.end(); ++it)
        std::cout << *it_2 << " ";
    std::cout << std::endl << std::endl;



    //test met andere underlying container
    //test met replace std::list

}