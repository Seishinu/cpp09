/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:08:12 by ynuiga            #+#    #+#             */
/*   Updated: 2023/04/02 14:26:37 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &copy ): mymap(copy.mymap) {
}

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &copy ) {
	if (this != &copy)
		mymap = copy.mymap;
	return *this;
}

bool BitcoinExchange::isvalid( const std::string &line ) {
	std::stringstream ss(line);
	int year, month, day;
	char dash1, dash2, pipe;
	double val;

	ss >> year >> dash1 >> month >> dash2 >> day >> pipe >> val;
	if (((year == 2009 && month == 1 && day == 1) || (year < 2009 || dash1 != '-' || month < 1 || month > 12 || dash2 != '-' ||
		day < 1 || day > 31 || pipe != '|')) && line.compare("date | value")) {
		std::cerr << "Error : bad input => " << line << std::endl;
		return false;
	}
	else if (!ss.eof() && line.compare("date | value")) {
		std::cerr << "Error : bad input => " << line << std::endl;
		return false;
	}
	else if (val < 0.0 || val > 1000.0) {
		if (val < 0.0) {
			std::cerr << "Error : not a positive number." << std::endl;
			return false;
		}
		std::cerr << "Error : number too large." << std::endl;
		return false;
	}
	return (ss.eof() && year >= 2009 && dash1 == '-' && month >= 1 && month <= 12 &&
		dash2 == '-' && day >= 1 && day <= 31 && pipe == '|' && val >= 0.0 && val <= 1000.0);
}

std::string BitcoinExchange::datakeyExtract( const std::string &line ) {
	size_t comma = line.find(",");
	std::string key = line.substr(0, comma);
	return (key);
}

double BitcoinExchange::datavalExtract( const std::string &line ) {
	if (line.at(0) >= '0' && line.at(0) <= '9') {
		size_t comma = line.find(",");
		std::string valstr = line.substr(comma + 1, line.size());
		double val = std::stod(valstr);
		return (val);
	}
	return 0;
}

std::string BitcoinExchange::keyExtract( const std::string &line ) {
	size_t pipe = line.find("|");
	while (line.at(pipe - 1) == ' ' || line.at(pipe - 1) == '\t')
		pipe--;
	std::string key = line.substr(0, pipe);
	return (key);
}

double BitcoinExchange::valExtract( const std::string &line ) {
	size_t pipe = line.find("|");
	std::string valstr = line.substr(pipe + 1, line.size());
	double val = std::stod(valstr);
	return (val);
}

void BitcoinExchange::exchangecalc( std::__1::string key, double *val ) {
	std::map<std::string, double>::iterator it;
	it = this->mymap.find(key);
	if (it == mymap.end()) {
		it = mymap.lower_bound(key);
		it--;
	}
	*val *= it->second;
}

void BitcoinExchange::insertion( std::string key, double val ) {
	this->mymap.insert(std::pair<std::string, double>(key, val));
}

BitcoinExchange::~BitcoinExchange() {
}