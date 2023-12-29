/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 03:05:45 by kpuwar            #+#    #+#             */
/*   Updated: 2023/12/29 05:22:59 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool RPN::isOperator(const std::string& token) {
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::evaluateRPN(const std::string& expression) {
	std::stack<int> stack;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (isdigit(token[0])) {
			stack.push(atoi(token.c_str()));
		} else if (isOperator(token)) {
			if (stack.size() < 2) {
				cout << "Error: Insufficient operands for operation\n";
				return -1;
			}
			int operand2 = stack.top();
			stack.pop();
			int operand1 = stack.top();
			stack.pop();

			if (token == "+") {
				stack.push(operand1 + operand2);
			} else if (token == "-") {
				stack.push(operand1 - operand2);
			} else if (token == "*") {
				stack.push(operand1 * operand2);
			} else if (token == "/") {
				if (operand2 == 0) {
					cout << "Error: Division by zero" << endl;
					return -1;
				}
				stack.push(operand1 / operand2);
			}
		} else {
			cout << "Error: Invalid token '" << token << "'" << endl;
			return -1;
		}
	}

	if (stack.size() != 1) {
		cout << "Error: Invalid expression" << endl;
		return -1;
	}

	return stack.top();
}
