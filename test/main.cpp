#include <iostream>
class A 
{
    public:
        int a;
        A() : a(1){}
};


class B : virtual public A
{
    public:
        
        B() {this->a = 2;}
};

class C : virtual public A
{
    public:
        C() {this->a = 3;}
};

class D : public B, public C
{
    public:
    int b;
    int c;
        D() 
        { 
            
            b = B::a;
            c = C::a;
        }
};

int main()
{
    D test;

    std::cout << test.a << std::endl;
    std::cout << test.b << std::endl;
}