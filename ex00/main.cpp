/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:54:23 by ynuiga            #+#    #+#             */
/*   Updated: 2023/04/02 14:21:27 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main( int ac, char **av ) {
	if (ac == 2)
	{
		BitcoinExchange btc;
		std::ifstream file(av[1]);
		std::ifstream datafile("data.csv");
		std::string line;
		std::string key;
		std::string datakey;
		double val;
		double dataval;

		if (!file.is_open() || !datafile.is_open()) {
			std::cerr << "UNABLE TO OPEN FILE TO READ!" << std::endl;
			return CANTOPENFILE;
		}
		while (std::getline(datafile, line)) {
			datakey = btc.datakeyExtract(line);
			dataval = btc.datavalExtract(line);
			btc.insertion(datakey, dataval);
		}
		while (std::getline(file, line)) {
			for(std::string::iterator it = line.begin(); it != line.end(); it++) {
				if (*it == ',')
					*it = '.';
			}
			if (btc.isvalid(line)) {
				key = btc.keyExtract(line);
				val = btc.valExtract(line);
				std::cout << key << " => " << val << " = ";
				btc.exchangecalc( key, &val );
				std::cout << val << std::endl;
			}
		}
		file.close();
		datafile.close();
		return 0;
	}
	std::cerr << "Wrong Number Of Arguments!" << std::endl;
	return (UNVALIDNUMBERARGS);
}
