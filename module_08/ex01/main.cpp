#include "Span.hpp"

int main()
{
    Span simple = Span(5);

    simple.addNumber(6);
    simple.addNumber(4);
    simple.addNumber(5);
    simple.addNumber(5);
    simple.addNumber(5);
    try{simple.addNumber(5);}
    catch(const std::length_error &e){std::cout << e.what() << std::endl;}
    simple.print();
    std::cout << "shortest span = " << simple.shortestSpan() << std::endl;
    std::cout << "longest span = " << simple.longestSpan() << std::endl;
    std::cout << "\n\n";

    Span empty;
    empty.print();
    try{empty.shortestSpan();}
    catch(std::range_error &e){std::cout << e.what() << std::endl;}
    std::cout << "\n\n";

    Span simple_two(5);
    
    simple_two.addNumber(42);
    simple_two.addNumber(5);
    simple_two.addNumber(9939);
    simple_two.addNumber(345);
    simple_two.addNumber(3213453);
    try{simple_two.addNumber(233);}
    catch(const std::length_error &e){std::cout << e.what() << std::endl;}
    simple_two.print();
    std::cout << "shortest span = " << simple_two.shortestSpan() << std::endl;
    std::cout << "longest span = " << simple_two.longestSpan() << std::endl;
    std::cout << "\n\n";
    
    // Span huge(20000);
    // std::vector<int> vectortje(10000);
    // for(int i = 0; i < 10000; i++)
    //     vectortje[i] = i;
    // huge.addRange(vectortje.begin(), vectortje.end());
    // huge.addRange(vectortje.begin(), vectortje.end());
    // huge.print();
    // try{huge.addRange(vectortje.begin(), vectortje.end());}
    // catch(const std::range_error &e){std::cout << e.what() << std::endl;}
}