/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:33:58 by bszikora          #+#    #+#             */
/*   Updated: 2025/11/27 19:39:58 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;

// Test addRange function
std::cout << "\n=== Testing addRange ===" << std::endl;
Span sp2(10);
std::vector<int> numbers;
numbers.push_back(1);
numbers.push_back(2);
numbers.push_back(3);
numbers.push_back(4);
numbers.push_back(5);

sp2.addRange(numbers.begin(), numbers.end());
std::cout << "Added range of 5 numbers" << std::endl;
std::cout << "Span size: " << sp2.size() << std::endl;
std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

return 0;
}
