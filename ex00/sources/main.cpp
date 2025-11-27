/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:47:03 by bszikora          #+#    #+#             */
/*   Updated: 2025/10/28 13:34:04 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"


int main()
{
	std::vector<int> vec;
	for (int i = 1; i <= 5; i++)
	{
		vec.push_back(i);
	}

	try {
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found in vector: " << *it << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Vector: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(vec, 42);
		std::cout << "Found in vector: " << *it << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Vector: " << e.what() << std::endl;
	}

	// Test with std::list
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	try {
		std::list<int>::iterator it = easyfind(lst, 20);
		std::cout << "Found in list: " << *it << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "List: " << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator it = easyfind(lst, 99);
		std::cout << "Found in list: " << *it << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "List: " << e.what() << std::endl;
	}

	// Test with std::deque
	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);

	try {
		std::deque<int>::iterator it = easyfind(deq, 200);
		std::cout << "Found in deque: " << *it << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Deque: " << e.what() << std::endl;
	}

	return 0;
}