/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:40:22 by ynuiga            #+#    #+#             */
/*   Updated: 2023/03/30 15:06:41 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <cmath>
#include <sstream>

class RPN {
	private:
		std::stack<int> mystack;
	public:
		RPN();
		RPN( std::string );
		RPN( const RPN & );
		RPN &operator=( const RPN & );
		~RPN();
		int ctoi(char c);
		int perform(int op1, int op2, char operation);
		int isoperator(char c);
		int isoperand(char c);
		void postfix( std::string mathexp );
};