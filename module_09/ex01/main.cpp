#include <algorithm>
#include <iostream>
#include <stack>

#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4

template <typename T, typename Operator>
void apply_operator(std::stack<T>& result, Operator op)
{
    T x = result.top();
    result.pop();
    T y = result.top();
    result.pop();
    result.push(op(y, x));
}


int eval_expresion(std::string expression)
{
	std::stack<int> result;
	for (int i = 0; expression[i]; i++)
	{
		
		if (isdigit(expression[i]))
		{
			result.push(expression[i] - 48);
			continue;
		}
		else if(expression[i] == '+')
			apply_operator(result, std::plus<int>());
		else if(expression[i] == '-')
			apply_operator(result, std::minus<int>());
		else if(expression[i] == '*')
			apply_operator(result, std::multiplies<int>());
		else if(expression[i] == '/')
			apply_operator(result, std::divides<int>());
	}
	if (result.size() == 2)
	{
		std::cout << "Error." << std::endl;
		exit(0);
	}
	return (result.top());
}

int main(int ac, char **argv)
{
	if (ac != 2)
		std::cout << "1 argument required." << std::endl;
	else {
		std::stack<char> polish_stack;
		std::string polish_string = argv[1];
		std::string available_chars = "0123456789+-*/";

		std::string::iterator end_pos = std::remove(polish_string.begin(), polish_string.end(), ' ');
		polish_string.erase(end_pos, polish_string.end());


		for(int i = polish_string.length() - 1; i > -1; i--)
		{
			if (available_chars.find(polish_string[i]) == std::string::npos)
			{
				std::cout << "invalid characters found." << std::endl;
				exit(0);
			}
			polish_stack.push(polish_string[i]);
		}
		std::cout << eval_expresion(polish_string) << std::endl;
	}
}