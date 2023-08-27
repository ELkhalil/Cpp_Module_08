/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:13:44 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/27 15:38:25 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Default constructor
Span::Span( void ) {}

Span::Span(unsigned int n) : _N(n) {}

// Copy constructor
Span::Span(const Span& other) : _N(other._N), _numbers(other._numbers) {}

// Copy assignment operator
Span& Span::operator=(const Span& other) 
{
    if (this != &other) 
    {
        _N = other._N;
        _numbers = other._numbers;
    }
    return *this;
}

// Destructor
Span::~Span() {}

// Span Member functions
void Span::addNumber(int number)
{
    if (_numbers.size() >= _N)
        throw std::runtime_error("Span is at the maximum Size");
    _numbers.push_back(number);
}

int Span::shortestSpan() const
{
    if (_numbers.size() <= 1)
        throw std::runtime_error("Cannot calculate shortest span: not enough data.");

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int shortestSpan = std::abs(sortedNumbers[1] - sortedNumbers[0]);
    for (size_t i = 2; i < sortedNumbers.size(); i++)
    {
        int span = std::abs(sortedNumbers[i + 1] - sortedNumbers[i]);
        if (span < shortestSpan)
            shortestSpan = span;
    }
    return shortestSpan;
}



int Span::longestSpan() const
{
    if (_numbers.size() <= 1)
        throw std::runtime_error("Cannot calculate longest span: not enough data.");

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int minNumber = *std::min_element(sortedNumbers.begin(), sortedNumbers.end());
    int maxNumber = *std::max_element(sortedNumbers.begin(), sortedNumbers.end());
    return std::abs(maxNumber - minNumber);
}

void    Span::print_Span() const
{
    for(size_t i = 0; i < _numbers.size(); i ++)
        std::cout << _numbers[i] << " ";
    std::cout << std::endl;
}