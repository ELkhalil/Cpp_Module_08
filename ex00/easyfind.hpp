/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:31:49 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/22 22:05:09 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template < typename T>
void easyfind ( T& container, int tofind )
{
    typename T::iterator iter = std::find(container.begin(), container.end(), tofind);
    if (iter == container.end())
        std::cerr << "value Not found" << std::endl;
    else
        std::cout << "Value Found" << std::endl;
}

#endif