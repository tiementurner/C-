#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Sed
{
    public:
    void        start_sedding();
    std::string replace_string(std::string line, size_t pos);
                Sed(std::string, std::string, std::string);
                ~Sed();
    
    private:
    std::string     file_to_read;
    std::ifstream   opened_file;
    std::string     to_replace;
    std::string     replace;
};