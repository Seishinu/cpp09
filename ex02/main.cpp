/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:29:09 by ynuiga            #+#    #+#             */
/*   Updated: 2023/04/02 16:05:26 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac > 1)
	{
		int arr[ac - 1];
		for (int i = 1; i < ac ; i++)
		{
			try {
				arr[i - 1] = std::stoi(av[i]);
				if (arr[i - 1] < 0)
				{
					std::cerr << "Argumnets Should Be Valid Positive Intigers!" << std::endl;
					return 1;
				}	
			}
			catch(std::invalid_argument &e){
				std::cout << e.what() << std::endl;
				return 1;	
			}
			catch(std::out_of_range &e){
				std::cout << e.what() << std::endl;
				return 1;	
			}
		}
		PmergeMe merge(arr, ac - 1);
		return 0;
	}
	return 1;
}
