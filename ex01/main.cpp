/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:57:31 by kpuwar            #+#    #+#             */
/*   Updated: 2023/12/29 05:26:09 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2) {
		cout << "usage: ./RPN \"<inverted Polish mathematical expression>\"" << endl;
		return EXIT_FAILURE;
	}

	int result = RPN::evaluateRPN(argv[1]);
	if (result == -1)
		return EXIT_FAILURE;
	else
		cout << result << endl;

	return EXIT_SUCCESS;
}
