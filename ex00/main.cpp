/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:31:36 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/27 13:30:47 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() 
{
    std::cout << "____ Testing Vector Container ____" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    std::cout << "does the Vector Container have : 10" << std::endl;
    easyfind(vec, 10);
    std::cout << "does the Vector Container have : 500" << std::endl;
    easyfind(vec, 500);
    std::cout << "____________________________" << std::endl << std::endl;

    std::cout << "____ Testing List Container ____" << std::endl;
    std::list<int> lst;
    lst.push_back(78);
    lst.push_back(22);
    lst.push_back(13);
    lst.push_back(99);
    lst.push_back(107);

    std::cout << "does the List Container have : 22" << std::endl;
    easyfind(lst, 22);
    std::cout << "does the List Container have : 88" << std::endl;
    easyfind(lst, 88);
    std::cout << "________________________________________" << std::endl;

    return 0;
}