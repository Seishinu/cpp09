/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:02:22 by ynuiga            #+#    #+#             */
/*   Updated: 2023/04/01 14:48:22 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <deque>

class PmergeMe {
	private:
		int* arr;
		int size;
		std::vector<int> myvec;
		std::deque<int> myq;
	public:
		PmergeMe();
		PmergeMe( int*,int );
		PmergeMe( const PmergeMe & );
		PmergeMe &operator=( const PmergeMe & );
		~PmergeMe();
		void printdeqval();
		void printvecval();
		void vecmergesort(std::vector<int>&, int, int);
		void vecmerge(std::vector<int>&, int, int, int);
		void qmergesort(std::deque<int>&, int, int);
		void qmerge(std::deque<int>&, int, int, int);
};