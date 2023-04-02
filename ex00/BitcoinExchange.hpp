/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:54:19 by ynuiga            #+#    #+#             */
/*   Updated: 2023/03/30 13:08:56 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
# define UNVALIDNUMBERARGS 1
# define CANTOPENFILE 2

class BitcoinExchange {
	private:
		std::map<std::string, double> mymap;
	public:
		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange & );
		BitcoinExchange &operator=( const BitcoinExchange & );
		~BitcoinExchange();
		bool isvalid( const std::string &line );
		std::string datakeyExtract( const std::string &line );
		double datavalExtract( const std::string &line );
		std::string keyExtract( const std::string &line );
		double valExtract( const std::string &line );
		void exchangecalc( std::string , double* );
		void insertion( std::string key, double val );
};