#pragma once

#include <string>
#include <iostream>
#include <limits>
#include <iomanip>


#define CHAR 0
#define INT  1
#define FLOAT 2
#define DOUBLE 3


typedef struct s_c
{
    char        char_literal;
    int         int_literal;
    float       float_literal;
    double      double_literal;
}               conversion;

void write_as_char(conversion &literal, int type);
void write_as_int(conversion &literal, int type);
void write_as_float(conversion &literal, int type);
void write_as_double(conversion &literal, int type);

int check_int(std::string string, long number);
int check_char(std::string string);
int check_double(std::string string, long number);
int check_float(std::string string, long number);
int detect_scalar(const std::string &string, conversion &literal);

