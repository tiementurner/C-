#pragma once

#include <string>
#include <float.h>
#include <limits.h>
#include <iostream>

#define CHAR 1
#define INT  2
#define FLOAT 3
#define DOUBLE 4

#define NAN 1
#define INF 2
#define MIN_INF 3

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        static bool check_char(std::string literal);
        static bool check_int(std::string literal);
        static bool check_double(std::string literal);
        static bool check_float(std::string literal);
    public:
        static std::string convert(std::string literal);
};