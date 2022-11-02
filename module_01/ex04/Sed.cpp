#include "Sed.hpp"

Sed::Sed(std::string file_to_read, std::string to_replace, std::string replace) :
file_to_read(file_to_read), to_replace(to_replace), replace(replace){}

Sed::~Sed(){}

std::string Sed::replace_string(std::string line, size_t pos)
{
    std::string new_line;
    int         j;

    j = 0;
    for(std::string::size_type i = 0; i < line.length(); i++)
    {
        if (i == pos)
        {
            i += to_replace.length() - 1;
            pos = line.find(this->to_replace, pos + 1);
            new_line = new_line.append(this->replace);
        }
        else
            new_line += line[i];
    }
    return (new_line);
}

void Sed::start_sedding()
{
    std::string     buffer;
    std::string     new_file_name;
    std::string     replaced_string;
    size_t          found;

    this->opened_file.open(this->file_to_read);
    if (this->opened_file.is_open())
    {
        new_file_name = this->file_to_read.append(".replace");
        std::ofstream new_file(new_file_name);
        while (std::getline(this->opened_file, buffer))
        {
            found = buffer.find(this->to_replace);
            if (found != std::string::npos)
            {
                replaced_string = replace_string(buffer, found);
                new_file << replaced_string << std::endl;
            }
            else
                new_file << buffer << std::endl;
        }     
    }
    else
    {
        std::cout << "Error opening file" << std::endl;
    }
}