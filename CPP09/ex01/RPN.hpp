#ifndef RPN_HPP
# define RPN_HPP
#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cstdlib>

class RPN
{
private:
	std::stack<int> _stack;
	void _performOperation(char op)
	{
		if (_stack.size() < 2)
			throw std::runtime_error("Error: Not enough operands");

		int b = _stack.top();
		_stack.pop();
		int a = _stack.top();
		_stack.pop();

		switch (op)
		{
			case '+':
				_stack.push(a + b);
				break;
			case '-':
				_stack.push(a - b);
				break;
			case '*':
				_stack.push(a * b);
				break;
			case '/':
				if (b == 0)
					throw std::runtime_error("Error: Division by zero");
				_stack.push(a / b);
				break;
			default:
				throw std::runtime_error("Error: Invalid operator");
		}
	}
	public:
	RPN() {}
	RPN(const RPN &other) : _stack(other._stack) {}
	RPN &operator=(const RPN &other)
	{
		if (this != &other)
			_stack = other._stack;
		return *this;
	}
	~RPN() {}
	void evaluate(const std::string &expression)
	{
		std::istringstream iss(expression);
		std::string token;

		while (iss >> token)
		{
			if (isdigit(token[0]))
			{
				_stack.push(std::atoi(token.c_str()));
			}
			else if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
			{
				_performOperation(token[0]);
			}
			else
			{
				throw std::runtime_error("Error: Invalid token");
			}
		}

		if (_stack.size() != 1)
			throw std::runtime_error("Error: The stack should contain exactly one result");

		std::cout << _stack.top() << std::endl;
	}

};

#endif
