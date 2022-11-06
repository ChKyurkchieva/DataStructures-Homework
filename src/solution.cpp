#include "solution.h"
#include <stack>
using std::stack;

bool isCorrect(const char* expression)
{
	const char x = '(';
	const char y = '{';
	const char z = '[';
	const char _x = ')';
	const char _y = '}';
	const char _z = ']';
	stack<char> expressionStack;
	size_t expressionSize = strlen(expression);
	for (size_t i = 0; i < expressionSize; ++i)
	{
		switch (expression[i])
		{
		case x:
		{
			expressionStack.push(x);
			break;
		}
		case y:
		{
			expressionStack.push(y);
			break;
		}
		case z:
		{
			expressionStack.push(z);
			break;
		}
		case _x:
		{
			if (expressionStack.empty() || expressionStack.top() != x)
			{
				return false;
			}
			else
			{
				expressionStack.pop();
				break;
			}
		}
		case _y:
		{
			if (expressionStack.empty() || expressionStack.top() != y)
			{
				return false;
			}
			else
			{
				expressionStack.pop();
				break;
			}
		}
		case _z:
		{
			if (expressionStack.empty() || expressionStack.top() != z)
			{
				return false;
			}
			else
			{
				expressionStack.pop();
				break;
			}
		}
		}
	}
	return expressionStack.empty();
}
