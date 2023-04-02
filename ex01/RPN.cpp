/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:42:51 by ynuiga            #+#    #+#             */
/*   Updated: 2023/04/02 15:08:11 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {	
};

RPN::RPN( const RPN &copy ): mystack(copy.mystack) {
};

RPN::RPN(std::string mathexp) {
	this->postfix(mathexp);
}

int RPN::ctoi(char c) {
	int val = c - '0';
	return val;
}

int RPN::isoperand(char c) {
	if(c >= '0' && c <= '9')
		return 0;
	return 1;
}

int RPN::isoperator(char c) {
	if (c == '+' || c == '*' || c == '/' || c == '-')
		return 0;
	return 1;
}

int RPN::perform(int op1, int op2, char operation) {
	if (operation == '+')
		return op2+op1;
	else if (operation == '*')
		return op2*op1;
	else if (operation == '-')
		return op2-op1;
	else if (operation == '/')
		return op2/op1;
	else
		return INT_MIN;
}

void RPN::postfix(std::string mathexp) {
	int a, b;
	std::string::iterator it;

	for(it = mathexp.begin(); it != mathexp.end(); it++)
	{
		if (isoperand(*it) && isoperator(*it) && *it != 32 && *it != '\t') {
			std::cerr << "ERROR => unvalid character!" << std::endl;
			return ;
		}
		else if (!isoperator(*it)) {
			if (!isoperator(*(it + 1))) {
				std::cerr << "ERROR => unvalid operation structor!" << std::endl;
				return ;
			}
			if (mystack.size() < 2) {
				std::cerr << "ERROR => size less than two! " << std::endl;
				return ;
			}
			a = mystack.top();
			mystack.pop();
			b = mystack.top();
			mystack.pop();
			mystack.push(perform(a, b, *it));
		}
		else if (!isoperand(*it))
			mystack.push(ctoi(*it));
	}
	std::cout << mystack.top() << std::endl;
	return ;
}

RPN &RPN::operator=( const RPN &copy ) {
	if (this != &copy)
		this->mystack = copy.mystack;
	return *this;
};

RPN::~RPN() {
};