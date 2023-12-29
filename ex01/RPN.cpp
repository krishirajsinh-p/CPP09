/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 03:05:45 by kpuwar            #+#    #+#             */
/*   Updated: 2023/12/30 00:45:02 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN &RPN::operator=(const RPN &rhs)
{
	(void)rhs;
	return *this;
}

static bool isOperator(const string &token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::evaluateRPN(const string &expression)
{
	std::stack<int> stack;
	std::istringstream iss(expression);
	string token;

	while (iss >> token)
	{
		if (isdigit(token[0]))
			stack.push(atoi(token.c_str()));
		else if (isOperator(token))
		{
			if (stack.size() < 2)
				throw (string)("Error: Insufficient operands for operation");
			int operand2 = stack.top();
			stack.pop();
			int operand1 = stack.top();
			stack.pop();

			if (token == "+")
				stack.push(operand1 + operand2);
			else if (token == "-")
				stack.push(operand1 - operand2);
			else if (token == "*")
				stack.push(operand1 * operand2);
			else if (token == "/")
			{
				if (operand2 == 0)
					throw (string)("Error: Division by zero");
				stack.push(operand1 / operand2);
			}
		}
		else
			throw (string)("Error: Invalid token '" + token + "'");
	}

	if (stack.size() != 1)
		throw (string)("Error: Invalid expression");

	return stack.top();
}
