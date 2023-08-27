/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:13:33 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/27 15:38:15 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>

class   Span
{
public:
    Span                ( unsigned int n );
    Span                ( Span const& other );
    ~Span               ( void );
    Span&               operator=( Span const& other );
    
    void                addNumber(int number);

    template <typename T>
    void                addNumber(T begin, T end)
    {
        while (begin != end)
        {
            Span::addNumber(*begin);
            begin++;
        }
    }

    int                 shortestSpan() const;
    int                 longestSpan() const;
    void                print_Span() const;
private:
    unsigned int        _N;
    std::vector<int>    _numbers;
    Span                ( void );
};
#endif