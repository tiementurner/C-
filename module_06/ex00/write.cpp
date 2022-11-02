#include "header.hpp"

void write_as_char(conversion &literal, int type)
{
    std::cout << "char: ";
    char c = 0;
    switch(type)
    {
        case CHAR:
            c = literal.char_literal;
            break ;
        case INT:
            c = static_cast<char>(literal.int_literal);
            break;
        case FLOAT:
            c = static_cast<char>(literal.float_literal);
            break;
        case DOUBLE:
            c = static_cast<char>(literal.double_literal);
            break;
    }
    if (static_cast<int>(c) > 127 || static_cast<int>(c) <= 0)
        std::cout << "non displayable";
    else
        std::cout << c;
    std::cout << std::endl;
}

void write_as_int(conversion &literal, int type)
{
    std::cout << "int: ";
    int i = 0;
    switch(type)
    {
        case CHAR:
            i = static_cast<int>(literal.char_literal);
            break ;
        case INT:
            i = literal.int_literal;
            break;
        case FLOAT:
            i = static_cast<int>(literal.float_literal);
            if (static_cast<long>(i) != static_cast<long>(literal.float_literal))
            {
                std::cout << "impossible" << std::endl;
                return ;
            }
            break;
        case DOUBLE:
            i = static_cast<int>(literal.double_literal);
            
            if (static_cast<long>(i) != static_cast<long>(literal.double_literal))
            {
                std::cout << "impossible" << std::endl;
                return ;
            }
            break;
    }
    std::cout << i << std::endl;
}

void write_as_float(conversion &literal, int type)
{
    std::cout << "float: ";
    
    float f = 0;
    switch(type)
    {
        case CHAR:
            f = static_cast<float>(literal.char_literal);
            std::cout << f << ".0f" << std::endl;
            return;
            break ;
        case INT:
            f = static_cast<float>(literal.int_literal);
            std::cout << f << ".0f" << std::endl;
            return;
            break;
        case FLOAT:
            f = literal.float_literal;
            if (static_cast<float>(static_cast<long>(f)) == f)
            {
                std::cout << f << ".0f" << std::endl;
                return ;
            }
            break;
        case DOUBLE:
            f = static_cast<float>(literal.double_literal);
            if (static_cast<float>(static_cast<long>(f)) == f)
            {
                std::cout << f << ".0f" << std::endl;
                return ;
            }
            break;
    }
    std::cout << f << "f" << std::endl;
}

void write_as_double(conversion &literal, int type)
{
    std::cout << "double: ";
    double d = 0;
    switch(type)
    {
        case CHAR:
            d = static_cast<double>(literal.char_literal);
            std::cout << d << ".0" << std::endl;
            return ;
            break ;
        case INT:
            d = static_cast<double>(literal.int_literal);
            std::cout << d << ".0" << std::endl;
            return ;
            break;
        case FLOAT:
            d = static_cast<double>(literal.float_literal);
            if (static_cast<double>(static_cast<long>(d)) == d)
            {
                std::cout << d << ".0" << std::endl;
                return ;
            }
            break;
        case DOUBLE:
            d = literal.double_literal;
            if (static_cast<double>(static_cast<long>(d)) == d)
            {
                std::cout << d << ".0" << std::endl;
                return ;
            }
            break;
    }
    std::cout << d << std::endl;
}