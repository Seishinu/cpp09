/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:09:17 by ynuiga            #+#    #+#             */
/*   Updated: 2023/04/02 14:30:44 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac == 2) {
		RPN myrpn((std::string)av[1]);
		return 0;
	}
	std::cerr << "Wrong Arguments!"<< std::endl;
	return 1;
}
