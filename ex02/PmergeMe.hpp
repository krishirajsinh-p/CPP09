/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 06:36:37 by kpuwar            #+#    #+#             */
/*   Updated: 2023/12/30 12:21:09 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::string;

class PmergeMe
{
	private:
		std::vector<int> mainChainVec;
		std::vector<int> pendChainVec;

		std::list<int> mainChainList;
		std::list<int> pendChainList;

		int struggler;
		bool hasStruggler;

		double timeForVec;
		double timeForList;

		void mergeInsertionSortVec(std::vector<int> &vec);
		void mergeInsertChainsVec();

		void mergeInsertionSortList(std::list<int> &lst);
		void mergeInsertChainsList();

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& rhs);

		void loadElementsToVec(std::string str);
		void sortWithVec();

		void loadElementsToList(std::string str);
		void sortWithList();

		void printInfoBefore();
		void printInfoAfter();

		double getTimeForVec();
		double getTimeForList();
};

#endif
