/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:34:06 by bszikora          #+#    #+#             */
/*   Updated: 2025/10/28 14:52:45 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0)
{
}

Span::Span(unsigned int N) : _maxSize(N)
{
	_numbers.reserve(N);
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw SpanFullException();
	_numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = UINT_MAX;
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i-1]);
		if (span < minSpan)
			minSpan = span;
	}

	return minSpan;
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	std::vector<int>::const_iterator minElement = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator maxElement = std::max_element(_numbers.begin(), _numbers.end());

	return static_cast<unsigned int>(*maxElement - *minElement);
}

unsigned int Span::size() const
{
	return _numbers.size();
}

unsigned int Span::maxSize() const
{
	return _maxSize;
}

const char* Span::SpanFullException::what() const throw()
{
	return "Span is full: cannot add more numbers";
}

const char* Span::NoSpanException::what() const throw()
{
	return "No span can be found: need at least 2 numbers";
}

