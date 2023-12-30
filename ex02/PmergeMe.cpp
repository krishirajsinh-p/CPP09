/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 06:36:40 by kpuwar            #+#    #+#             */
/*   Updated: 2023/12/30 12:21:34 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : struggler(0), hasStruggler(false), timeForVec(0), timeForList(0) {}

PmergeMe::PmergeMe(const PmergeMe& src) {*this = src;}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
	if (this != &rhs) {
		mainChainVec = rhs.mainChainVec;
		pendChainVec = rhs.pendChainVec;

		mainChainList = rhs.mainChainList;
		pendChainList = rhs.pendChainList;

		struggler = rhs.struggler;
		hasStruggler = rhs.hasStruggler;

		timeForVec = rhs.timeForVec;
		timeForList = rhs.timeForList;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::mergeInsertionSortVec(std::vector<int> &vec)
{
	for (size_t i = 1; i < vec.size(); ++i)
	{
		int key = vec[i];
		size_t j = i;

		while (j > 0 && vec[j - 1] > key)
		{
			vec[j] = vec[j - 1];
			--j;
		}

		vec[j] = key;
	}
}

void PmergeMe::mergeInsertChainsVec()
{
	mergeInsertionSortVec(pendChainVec);

	for (std::vector<int>::iterator ip = pendChainVec.begin(); ip != pendChainVec.end(); ++ip)
	{
		std::vector<int>::iterator pos = std::upper_bound(mainChainVec.begin(), mainChainVec.end(), *ip);
		mainChainVec.insert(pos, *ip);
	}

	if (hasStruggler)
	{
		std::vector<int>::iterator pos = std::upper_bound(mainChainVec.begin(), mainChainVec.end(), struggler);
		mainChainVec.insert(pos, struggler);
	}
}

void PmergeMe::mergeInsertionSortList(std::list<int> &lst)
{
	std::list<int> result;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		std::list<int>::iterator pos = result.begin();
		while (pos != result.end() && *pos < *it)
		{
			++pos;
		}
		result.insert(pos, *it);
	}
	lst = result;
}

void PmergeMe::mergeInsertChainsList()
{
	mergeInsertionSortList(pendChainList);

	for (std::list<int>::iterator ip = pendChainList.begin(); ip != pendChainList.end(); ++ip)
	{
		std::list<int>::iterator pos = mainChainList.begin();
		while (pos != mainChainList.end() && *pos < *ip)
		{
			++pos;
		}
		mainChainList.insert(pos, *ip);
	}

	if (hasStruggler)
	{
		std::list<int>::iterator pos = mainChainList.begin();
		while (pos != mainChainList.end() && *pos < struggler)
		{
			++pos;
		}
		mainChainList.insert(pos, struggler);
	}
}

void PmergeMe::loadElementsToVec(std::string str)
{
	int num = atoi(str.c_str());
	pendChainVec.push_back(num);
}

void PmergeMe::loadElementsToList(std::string str)
{
	int num = atoi(str.c_str());
	pendChainList.push_back(num);
}

void PmergeMe::printInfoBefore()
{
	for (std::list<int>::iterator it = pendChainList.begin(); it != pendChainList.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void PmergeMe::printInfoAfter()
{
	for (std::list<int>::iterator it = mainChainList.begin(); it != mainChainList.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

double PmergeMe::getTimeForVec()
{
	return timeForVec;
}

double PmergeMe::getTimeForList()
{
	return timeForList;
}

void PmergeMe::sortWithVec()
{
	clock_t start = clock();
	mergeInsertChainsVec();
	clock_t end = clock();
	timeForVec = ((double)(end - start)) / CLOCKS_PER_SEC;
}

void PmergeMe::sortWithList()
{
	clock_t start = clock();
	mergeInsertChainsList();
	clock_t end = clock();
	timeForList = ((double)(end - start)) / CLOCKS_PER_SEC;
}
