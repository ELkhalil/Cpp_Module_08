/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:42:44 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/31 12:30:52 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    MutantStack     ( void ) {};
    MutantStack     (const MutantStack& other) : std::stack<T, Container>(other) {}
    MutantStack&    operator=( MutantStack const& other )
    {
        if (this != &other)
            this->c = other.c;
        return *this;
    };
    ~MutantStack ( void ) {};

    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    /* Default iterators */
    iterator begin() 
    {
        return this->c.begin();
    }
    iterator end()
    {
        return this->c.end();
    }

    /* Const iterators*/
    const_iterator begin() const
    {
        return this->c.begin();
    }
    const_iterator end() const 
    {
        return this->c.end();
    }

};

#endif