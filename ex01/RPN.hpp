/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:57:27 by kpuwar            #+#    #+#             */
/*   Updated: 2023/12/29 05:24:44 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;

class RPN
{
	public:
		RPN(){}
		~RPN(){}
		RPN(const RPN& src) {*this = src;}
		RPN& operator=(const RPN& rhs) {(void)rhs; return *this;}

		static bool isOperator(const std::string& token);
		static int evaluateRPN(const std::string& expression);
};

#endif
