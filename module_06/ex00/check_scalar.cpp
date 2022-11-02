#include "header.hpp"

int check_int(std::string string, long number)
{
    int i = 0;
    if (string[0] == '-')
        if (string[1] != '\0')
            i++;
    for(; string[i]; i++)
    {
        if (!isdigit(string[i]))
            return (0);
    }
    if (number > std::numeric_limits<int>::max() ||
        number < std::numeric_limits<int>::min())
        return (0);
    return (1);
}

int check_char(std::string string)
{
    if (!isdigit(string[0]) && !string[1])
        return (1);
    return (0);
}

int check_double(std::string string, long number)
{
    int i = 0;
    int dot = 0;
    if (string[0] == '-')
        if (string[1] != '\0')
            i++;
    for(; string[i]; i++)
    {
        if (string[i] == '.')
            dot++;
        if (dot > 1)
            return (0);
        if (!isdigit(string[i]) && string[i] != '.')
            return (0);
    }   
    if (number > std::numeric_limits<double>::max() ||
        number < -std::numeric_limits<double>::max())
        return (0);
    return (1);
}

int check_float(std::string string, long number)
{
    
    int i = 0;
    int dot = 0;
    if (string[0] == '-')
        if (string[1] != '\0')
            i++;
    for(; string[i]; i++)
    {
        if (string[i] == '.')
            dot++;
        if (dot > 1)
            return (0);
        if (!isdigit(string[i]) && string[i] != '.' && string[i] != 'f')
            return (0);
        if (string[i] == 'f' && string[i + 1] != '\0')
            return (0);
    }   
    if (number > std::numeric_limits<float>::max() ||
        number < -std::numeric_limits<float>::max())
        return (0);
    if (string[i - 1] != 'f')
        return (0);
    return (1);
}

int detect_scalar(const std::string &string, conversion &literal)
{
    long number;

    if (string.compare("nanf") == 0 || string.compare("inff") == 0 || string.compare("-inff") == 0)
    {
        literal.float_literal = std::stof(string);
        return (FLOAT);
    }
    if (string.compare("nan") == 0 || string.compare("inf") == 0 || string.compare("-inf") == 0)
    {
        literal.float_literal = std::stof(string);
        return (DOUBLE);
    }
    number = strtol(string.c_str(), NULL, 10);
    if (check_char(string))
        return (CHAR);
    if (check_int(string, number))
        return (INT);
    if (check_float(string,number))
        return (FLOAT);
    if (check_double(string, number))
        return (DOUBLE);
    return(-1)  ;
}