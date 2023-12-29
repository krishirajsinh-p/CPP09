/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:57:31 by kpuwar            #+#    #+#             */
/*   Updated: 2023/12/29 23:10:48 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char const *argv[])
{
	try {
		if (argc != 2)
			throw "usage: ./RPN \"<inverted Polish mathematical expression>\"";
		cout << "result: " << RPN::evaluateRPN(argv[1]) << endl;
	} catch(const string& error) {
		cout << error << endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
