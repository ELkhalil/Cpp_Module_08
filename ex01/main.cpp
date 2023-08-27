/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:13:50 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/27 15:40:25 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <list>

void    emptySpanTest( void )
{
    try
    {
        Span emptySpan(5);
        
        std::cout << "the shortest span is : " << emptySpan.shortestSpan() << std::endl;
        std::cout << "the longest span is : " << emptySpan.longestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
void    testingSingleElementSpan( void )
{
    try
    {
        Span span(1);
        span.addNumber(100);
        std::cout << "the shortest span is : " << span.shortestSpan() << std::endl;    
        std::cout << "the longest span is : " << span.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}
void    spanWithSmallCapacity( void )
{
    try
    {
        Span span(10);
    
        span.addNumber(23);
        span.addNumber(19);
        span.addNumber(65);
        span.addNumber(77);
        span.addNumber(9);
        span.addNumber(37);
        span.addNumber(58);
        span.addNumber(99);
        span.addNumber(110);
        span.addNumber(17);
            
        std::cout << "the shortest span is : " << span.shortestSpan() << std::endl;    
        std::cout << "the longest span is : " << span.longestSpan() << std::endl;
        
        std::cout << "testing the limitation if i try to add another element : " << std::endl;
        span.addNumber(100);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
void    largestSpanTest( void )
{
    try
    {
        Span largeSpan(10000);

        for (int i = 1; i <= 10000; i++)
            largeSpan.addNumber(i);
    
        std::cout << "the shortest span is : " << largeSpan.shortestSpan() << std::endl;    
        std::cout << "the longest span is : " << largeSpan.longestSpan() << std::endl;    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
void    subjectTest( void )
{
    try
    {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void    testingRangeIterators ( void )
{
    try
    {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);
        vec.push_back(50);

        Span    iterSpan(20);

        iterSpan.addNumber(vec.begin(), vec.end());
        iterSpan.print_Span();

        std::cout << "the shortest span is : " << iterSpan.shortestSpan() << std::endl;    
        std::cout << "the longest span is : " << iterSpan.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
int main( void )
{
    std::cout << "Subject Page Test : " << std::endl;
    subjectTest();
    std::cout << "------Subject Page Test End--------" << std::endl;
    std::cout << std::endl;

    std::cout << "Testing Empty span: " << std::endl;
    emptySpanTest();
    std::cout << "-------------------" << std::endl;

    std::cout << "Testing Single Element Span: " << std::endl;
    testingSingleElementSpan();
    std::cout << "-------------------" << std::endl;

    std::cout << "testing a normal small span of 10 integers : " << std::endl;
    spanWithSmallCapacity();
    std::cout << "-------------------" << std::endl;
    
    std::cout << "Testing Big Span with 10000 integers: " << std::endl;
    largestSpanTest();
    std::cout << "-------------------" << std::endl;

    std::cout << "Using The Range of iterators to fill a span: " << std::endl;
    testingRangeIterators();
    std::cout << "-------------------" << std::endl;
    return 0;
}
