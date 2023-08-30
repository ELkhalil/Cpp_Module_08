/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:51:14 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/30 13:20:59 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <vector>
#include <list>

void testingDefaultContainerDeque( void )
{
    MutantStack<int> mutantStack;

    for (int i = 0; i < 10; i++)
        mutantStack.push(i);
    
    std::cout << "Iterating through MutantStack: ";
    for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void testingExplicitContainer( void )
{
    MutantStack<int, std::vector<int> > stackVector;

    for (int i = 0; i < 10; i++)
        stackVector.push(i);

    MutantStack<int, std::vector<int> >::iterator it;

    std::cout << "Iterating through stackVector: ";
    for (it = stackVector.begin(); it != stackVector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Using your MutantStack
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "------------------" << std::endl;

    // Using std::list
    std::list<int> lstack;
    lstack.push_back(5);
    lstack.push_back(17);
    std::cout << lstack.back() << std::endl;
    lstack.pop_back();
    std::cout << lstack.size() << std::endl;
    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);
    //[...]
    lstack.push_back(0);
    std::list<int>::iterator lit = lstack.begin();
    std::list<int>::iterator lite = lstack.end();
    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    // Manually copy elements from std::list to std::stack
    std::stack<int> s2;
    while (!lstack.empty())
    {
        s2.push(lstack.front());
        lstack.pop_front();
    }

    return 0;
}