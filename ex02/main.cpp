/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 06:36:42 by kpuwar            #+#    #+#             */
/*   Updated: 2023/12/30 12:22:16 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{
	if (argc < 2) {
		cout << "usage: ./PmergeMe <positive int numbers>" << endl;
		return EXIT_FAILURE;
	}

	PmergeMe pmergeMe;

	for (int i = 1; i < argc; i++)
	{
		pmergeMe.loadElementsToVec(argv[i]);
		pmergeMe.loadElementsToList(argv[i]);
	}

	cout << "Before:\t"; pmergeMe.printInfoBefore();
	pmergeMe.sortWithVec();
	pmergeMe.sortWithList();
	cout << "After:\t"; pmergeMe.printInfoAfter();
	printf("Time to process a range of %d elements with std::vector<int> : %.6f us\n", argc - 1, pmergeMe.getTimeForVec());
	printf("Time to process a range of %d elements with std::list<int> : %.6f us\n", argc - 1, pmergeMe.getTimeForList());

	return EXIT_SUCCESS;
}
