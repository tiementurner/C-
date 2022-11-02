#include "header.hpp"

void    convert_to_actual(const std::string &string, conversion &literal, int &type)
{
    literal.char_literal = '\0';
    literal.int_literal = 0;
    literal.float_literal = 0;
    literal.double_literal = 0;

    switch(type)
    {
        case CHAR:
            literal.char_literal = static_cast<char>(string[0]);
            break;
        case INT:
            literal.int_literal = static_cast<int>(strtol(string.c_str(), NULL, 10));
            break;
        case FLOAT:
            literal.float_literal = static_cast<float>(std::stof(string));
            break;
        case DOUBLE:
            literal.double_literal = static_cast<double>(strtod(string.c_str(), NULL));
            break;
    }
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    if (str[i - 1] == 'f')
        i--;
    if (str[0] == '-')
        i--;
    return (i);
}

int main(int argc, char **argv)
{
    conversion literal;
    int type = 0;

    if (argc != 2)
        return (0);
    type = detect_scalar(argv[1], literal);
    if (type == -1)
    {
        std::cout << "Invalid input!" << std::endl;
        return (0);
    }
    convert_to_actual(argv[1], literal, type);
    std::cout << std::setprecision(ft_strlen(argv[1]) + 2);
    write_as_char(literal, type);
    write_as_int(literal, type);
    write_as_float(literal,type);
    write_as_double(literal, type);
}