/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:57:27 by kpuwar            #+#    #+#             */
/*   Updated: 2023/12/30 00:42:51 by kpuwar           ###   ########.fr       */
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
		RPN();
		~RPN();
		RPN(const RPN& src);
		RPN& operator=(const RPN& rhs);

		static int evaluateRPN(const string& expression);
};

#endif
