#pragma once
#include <string>
#include <iostream>
class Brain
{
    public:
    Brain();
    ~Brain();
    Brain(const Brain& other);
    Brain& operator = (const Brain &other);
    
    void    get_ideas_adress();
    private:
        std::string ideas[100];
};