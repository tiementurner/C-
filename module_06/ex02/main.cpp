#include "Classes.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>


Base* generate()
{
    int i;
    std::srand(time(NULL));
    i = rand() % 3;
    switch (i) {
        case 0:
        return new A;
        case 1:
        return new B;
        case 2:
        return new C;
    }
    std::cout << "error generating class" << std::endl;
    return (NULL);
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Class is of type A." << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "Class is of type B." << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "Class is of type C." << std::endl;
    return;
}

void identify (Base& p)
{
    try{
        A& refA = dynamic_cast<A&>(p);
        std::cout << "Class is of type A." << std::endl;
        (void)refA;
    }catch(...){}
        try{

        B& refB = dynamic_cast<B&>(p);
        std::cout << "Class is of type B." << std::endl;
        (void)refB;
    }catch(...){}
        try{
        C& refC = dynamic_cast<C&>(p);
        std::cout << "Class is of type C." << std::endl;
        (void)refC;
    }catch(...){}
    return;
}


int main()
{   
    A *classA = new A;
    B *classB = new B;
    C *classC = new C;
    identify(classA);
    identify(classB);
    identify(classC);
    identify(*classA);
    identify(*classB);
    identify(*classC);
    std::cout << std::endl << "randomly generated:" << std::endl;
    Base *random = generate();
    identify(random);
    identify(*random);
}