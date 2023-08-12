/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohei <kohei@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:33:54 by kohei             #+#    #+#             */
/*   Updated: 2023/08/06 18:52:13 by kohei            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <sstream>

class PmergeMe {
    public:
        typedef std::vector<unsigned int>::iterator vecItr;
        typedef std::vector<unsigned int>::const_iterator constvecItr;
        typedef std::list<unsigned int>::iterator listItr;
        typedef std::list<unsigned int>::const_iterator constlistItr;
        PmergeMe();
        PmergeMe(const std::vector<unsigned int> &vector);
        ~PmergeMe();
        PmergeMe(const PmergeMe &pmergeme);
        PmergeMe &operator=(const PmergeMe &pmergeme);
        void    measureAndSort();
        std::vector<unsigned int> getVec() const;
        std::list<unsigned int> getList() const;
    private:
        std::vector<unsigned int> vector_;
        std::list<unsigned int> list_;
        std::vector<unsigned int>    *InsertionSort(std::vector<unsigned int> *sorted, std::vector<unsigned int> &vector);
        std::list<unsigned int>    *InsertionSort(std::list<unsigned int> *sorted, std::list<unsigned int> &list);
        std::vector<unsigned int>    *mergeVectorInsertionSort();
        std::list<unsigned int>    *mergeListInsertionSort();
        void    vectorQuickSort(vecItr start, vecItr end);
};
#endif