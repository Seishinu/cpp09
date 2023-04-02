/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:52:00 by ynuiga            #+#    #+#             */
/*   Updated: 2023/04/02 16:32:38 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe( int *numbers , int nsize ): arr(numbers), size(nsize), myvec(arr, arr + size), myq(arr, arr + size) {
	std::cout << "Before : ";
	printvecval();
	std::clock_t vecstart_time = std::clock();
	vecmergesort(myvec, 0, size - 1);
	std::clock_t vecend_time = std::clock();
	std::cout << "After : ";
	printvecval();
	double time_elapsed = static_cast<double>(vecend_time - vecstart_time) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << size << " elements with std::[vector] : " << std::fixed << std::setprecision(5) << (time_elapsed * 1000000.0) << " us"<< std::endl;
	std::clock_t deqstart_time = std::clock();
	qmergesort(myq, 0, size - 1);
	std::clock_t deqend_time = std::clock();
	time_elapsed = static_cast<double>(deqend_time - deqstart_time) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << size << " elements with std::[deque] : " << std::fixed << std::setprecision(5) << (time_elapsed * 1000000.0) << " us"<< std::endl;
}

PmergeMe::PmergeMe( const PmergeMe &copy ): arr(copy.arr) {
}

PmergeMe &PmergeMe::operator=( const PmergeMe &copy ) {
	if (this != &copy)
		this->arr = copy.arr;
	return *this;
}

void PmergeMe::printvecval() {
	std::vector<int>::iterator it;
	for (it = myvec.begin(); it != myvec.end(); it++)
		std::cout << "|"<< *it << "| ";
	std::cout << std::endl;
}

void PmergeMe::printdeqval() {
	std::deque<int>::iterator it;
	for (it = myq.begin(); it != myq.end(); it++)
		std::cout << "|"<< *it << "| ";
	std::cout << std::endl;
}

void PmergeMe::vecmerge(std::vector<int> &myvec, int left, int middle, int right) {
	int i, j;
	std::vector<int> tmp;

	i = left;
	j = middle + 1;
	while (i <= middle && j <= right) {
		if (myvec[i] <= myvec[j]) {
			tmp.push_back(myvec[i]);
			i++;
		}
		else {
			tmp.push_back(myvec[j]);
			j++;
		}
	}
	while (i <= middle) {
		tmp.push_back(myvec[i]);
		i++;
	}
	
	while (j <= right) {
		tmp.push_back(myvec[j]);
		j++;
	}
	for (int i = left; i <= right; i++)
		myvec[i] = tmp[i - left];
}

void PmergeMe::qmerge(std::deque<int> &myq, int left, int middle, int right) {
	int i, j;
	std::deque<int> tmp;

	i = left;
	j = middle + 1;
	while (i <= middle && j <= right) {
		if (myq[i] <= myq[j]) {
			tmp.push_back(myq[i]);
			i++;
		}
		else {
			tmp.push_back(myq[j]);
			j++;
		}
	}
	while (i <= middle) {
		tmp.push_back(myq[i]);
		i++;
	}
	
	while (j <= right) {
		tmp.push_back(myq[j]);
		j++;
	}
	for (int i = left; i <= right; i++)
		myq[i] = tmp[i - left];
}

void PmergeMe::vecmergesort(std::vector<int> &myvec, int left, int right) {
	if (left < right) {
		int middle = left + (right - left) / 2;
		vecmergesort(myvec, left, middle);
		vecmergesort(myvec, middle + 1, right);
		vecmerge(myvec, left, middle, right);
	}
	return ;
}

void PmergeMe::qmergesort(std::deque<int> &myq, int left, int right) {
	if (left < right) {
		int middle = left + (right - left) / 2;
		qmergesort(myq, left, middle);
		qmergesort(myq, middle + 1, right);
		qmerge(myq, left, middle, right);
	}
	return ;
}

PmergeMe::~PmergeMe() {
}
