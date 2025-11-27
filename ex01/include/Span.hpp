/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:34:14 by bszikora          #+#    #+#             */
/*   Updated: 2025/10/28 14:40:09 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <climits>

class Span
{
private:
	unsigned int _maxSize;
	std::vector<int> _numbers;

public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	template<typename Iterator>
	void addRange(Iterator begin, Iterator end);

	unsigned int size() const;
	unsigned int maxSize() const;

	class SpanFullException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

template<typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
	for (Iterator it = begin; it != end; ++it)
	{
		if (_numbers.size() >= _maxSize)
			throw SpanFullException();
		_numbers.push_back(*it);
	}
}

#endif

