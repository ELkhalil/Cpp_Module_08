/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:51:14 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/30 16:01:17 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <list>

void    testingDefaultContainerDeque( void )
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

void    testingExplicitContainer( void )
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

void    subjectTest( void )
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(111);
    mstack.push(64);
    mstack.push(0);

    // init iterators
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    MutantStack<int>::iterator recall = it;
    
    // testing increment and decrement of iterators
    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "--------------------------" << std::endl;
    std::cout << "Sorting the stack" << std::endl;

    MutantStack<int>::iterator tmp = recall;
    /* using constructor to create a new struct */
    sort(tmp, ite);

    while(recall != ite)
    {
        std::cout << *recall << std::endl;
        recall++;
    }
}

int main()
{
    subjectTest();
    testingDefaultContainerDeque();
    testingExplicitContainer();
    return 0;
}