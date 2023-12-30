/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 23:50:25 by kpuwar            #+#    #+#             */
/*   Updated: 2023/12/30 02:32:36 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
		cout << "usage: ./btc <path to input database>" << endl;
	BitcoinExchange::calculateBtc(argv[1]);
	return EXIT_SUCCESS;
}
