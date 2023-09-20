#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    if (this != &other)
        return(*this);
    return (*this);
}

bool ScalarConverter::check_char(std::string literal)
{
    if (!isdigit(literal[0]) && !literal[1])
        return (1);
    return (0);
}

bool ScalarConverter::check_int(std::string string)
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
    try {std::stoi(string);}
    catch (const std::exception &e){return (0);}
    return (1);
}

bool ScalarConverter::check_float(std::string literal)
{
    
    int i = 0;
    int dot = 0;
    if (literal[0] == '-')
        if (literal[1] != '\0')
            i++;
    for(; literal[i]; i++)
    {
        if (literal[i] == '.')
            dot++;
        if (dot > 1)
            return (0);
        if (!isdigit(literal[i]) && literal[i] != '.' && literal[i] != 'f')
            return (0);
        if (literal[i] == 'f' && literal[i + 1] != '\0')
            return (0);
    }
    if (literal[i - 1] != 'f')
        return (0);
    try {std::stof(literal);}
    catch (const std::exception &e){return (0);}
    return (1);
}

bool ScalarConverter::check_double(std::string literal)
{
    int i = 0;
    int dot = 0;
    if (literal[0] == '-')
        if (literal[1] != '\0')
            i++;
    for(; literal[i]; i++)
    {
        if (literal[i] == '.')
            dot++;
        if (dot > 1)
            return (0);
        if (!isdigit(literal[i]) && literal[i] != '.')
            return (0);
    }
    try {std::stod(literal);}
    catch (const std::exception &e){return (0);}
    return (1);
}


template<typename T>
static void cast(T actual){
    int scientific = 0;
    if (actual != actual)
        scientific = NAN;
    if (actual > FLT_MAX)
        scientific = INF;
    if (actual < -FLT_MAX)
        scientific = MIN_INF;

    std::cout << "char: ";
    if ((actual >= 32 && actual < 127) && scientific == 0)
        std::cout << static_cast<char>(actual) << std::endl;
    else
        std::cout << "impossible" << std::endl;
    
    std::cout << "int: ";
    if ((actual < INT32_MAX && actual > -INT32_MAX) && scientific == 0)
        std::cout << static_cast<int>(actual) << std::endl;
    else
        std::cout << "impossible" << std::endl;
    

    std::cout << "float: ";
    scientific == INF ? std::cout << "+":std::cout << "";
    std::cout << static_cast<float>(actual) << "f" << std::endl;

    std::cout << "double: ";
    scientific == INF ? std::cout << "+":std::cout << "";
    std::cout << static_cast<double>(actual) << std::endl;
}

std::string ScalarConverter::convert(std::string literal)
{
    int conversion_type = 0;
    if (check_char(literal) == true)
    {
        conversion_type = CHAR;
        cast<char>(literal[0]);
    }
    if (check_int(literal) == true && conversion_type == 0)
    {
        conversion_type = INT;
        cast<int>(std::stoi(literal));
    }
    if ((check_float(literal) || literal == "-inff" || literal == "+inff" || literal == "nanf") && conversion_type == 0)
    {
        conversion_type = FLOAT;
        cast<float>(std::stof(literal));
    }
    if ((check_double(literal) || literal == "-inf" || literal == "+inf" || literal == "nan") && conversion_type == 0)
    {
        conversion_type = DOUBLE;
        cast<double>(std::stod(literal));
    }
    if (conversion_type == 0)
        std::cout << "No valid type detected!" << std::endl;
    return(0);
}