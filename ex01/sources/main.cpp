/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:33:58 by bszikora          #+#    #+#             */
/*   Updated: 2026/02/17 15:46:38 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"
#include <iostream>
#include <vector>
#include <set>
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

 // Large-scale addRange test: 10,000 numbers
 std::cout << "\n=== Testing addRange with 10,000 numbers ===" << std::endl;
 try
 {
	const unsigned int N = 10000;
	Span sp3(N);
	std::vector<int> big;
	big.reserve(N);
	for (unsigned int i = 0; i < N; ++i)
		big.push_back(static_cast<int>(i));

	sp3.addRange(big.begin(), big.end());
	std::cout << "Added range of " << N << " numbers" << std::endl;
	std::cout << "Span size: " << sp3.size() << ", maxSize: " << sp3.maxSize() << std::endl;
	std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
 }
 catch (const std::exception& e)
 {
	std::cout << "Exception during 10,000 addRange test: " << e.what() << std::endl;
 }

	 // Source from std::set
	 std::cout << "\n=== Testing addRange from std::set ===" << std::endl;
	 try
	 {
		 Span sp4(6);
		 std::set<int> s;
		 s.insert(42);
		 s.insert(17);
		 s.insert(17); // duplicate ignored by set
		 s.insert(99);
		 s.insert(3);
		 s.insert(58);

		 sp4.addRange(s.begin(), s.end());
		 std::cout << "Added " << s.size() << " unique numbers from set" << std::endl;
		 std::cout << "Span size: " << sp4.size() << ", maxSize: " << sp4.maxSize() << std::endl;
		 std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
		 std::cout << "Longest span: " << sp4.longestSpan() << std::endl;
	 }
	 catch (const std::exception& e)
	 {
		 std::cout << "Exception during set addRange test: " << e.what() << std::endl;
	 }

return 0;
}
