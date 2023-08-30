/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:42:44 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/30 12:49:38 by aelkhali         ###   ########.fr       */
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
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    using std::stack<T, Container>::c;

    /* Default iterators */
    iterator begin() 
    {
        return c.begin();
    }
    iterator end()
    {
        return c.end();
    }

    /* Const iterators*/
    const_iterator begin() const 
    {
        return c.begin();
    }
    const_iterator end() const 
    {
        return c.end();
    }

};

#endif