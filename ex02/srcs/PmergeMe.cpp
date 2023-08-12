/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohei <kohei@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:33:56 by kohei             #+#    #+#             */
/*   Updated: 2023/07/24 22:05:22 by kohei            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): vector_(), list_()
{
    
}

PmergeMe::PmergeMe(const std::vector<unsigned int> &vector)
{
    constvecItr it = vector.begin();
    constvecItr ite = vector.end();
    this->vector_ = std::vector<unsigned int>(it, ite);
    this->list_ = std::list<unsigned int>(it, ite);
}

PmergeMe::~PmergeMe()
{
    
}

PmergeMe::PmergeMe(const PmergeMe &pmergeme): vector_(pmergeme.getVec()), list_(pmergeme.getList())
{
    
}

PmergeMe &PmergeMe::operator=(const PmergeMe &pmergeme)
{
    if (this != &pmergeme)
    {
        this->vector_ = pmergeme.getVec();
        this->list_ = pmergeme.getList();
    }
    return (*this);
}

std::vector<unsigned int> PmergeMe::getVec() const
{
    return (this->vector_);
}

std::list<unsigned int> PmergeMe::getList() const
{
    return (this->list_);
}

std::vector<unsigned int>    *PmergeMe::InsertionSort(std::vector<unsigned int> *sorted, std::vector<unsigned int> &vector)
{
    std::vector<unsigned int> tmp;
    for (vecItr it1 = vector.begin(); it1 != vector.end(); it1++)
    {
        if (sorted->size() == 0)
        {
            sorted->push_back(*(vector.begin()));
            continue ;
        }
        vecItr it2 = sorted->begin();
        for (; it2 != sorted->end(); it2++)
        {
            if (*it1 < *it2)
            {
                sorted->insert(it2, *it1);
                break ;
            }
        }
        if (it2 == sorted->end())
            sorted->push_back(*it1);
    }
    return (sorted);
}

std::vector<unsigned int>    *PmergeMe::mergeVectorInsertionSort()
{
    std::vector<unsigned int> biggerElements, smallerElements;
    std::vector<unsigned int> *sorted = new std::vector<unsigned int>;
    for (vecItr it = this->vector_.begin(); it != this->vector_.end(); it++)
    {
        unsigned int tmp = *it;
        it++;
        if (it == this->vector_.end())
        {
            smallerElements.push_back(tmp);
            break ;
        }
        if (tmp < *it)
        {
            biggerElements.push_back(*it);
            smallerElements.push_back(tmp);
        }
        else if (tmp >= *it)
        {
            biggerElements.push_back(tmp);
            smallerElements.push_back(*it);
        }
    }
    sorted = InsertionSort(sorted, biggerElements);
    sorted = InsertionSort(sorted, smallerElements);
    return (sorted);
}

std::list<unsigned int>    *PmergeMe::InsertionSort(std::list<unsigned int> *sorted, std::list<unsigned int> &list)
{
    std::list<unsigned int> tmp;
    for (listItr it1 = list.begin(); it1 != list.end(); it1++)
    {
        if (sorted->size() == 0)
        {
            sorted->push_back(*(list.begin()));
            continue ;
        }
        listItr it2 = sorted->begin();
        for (; it2 != sorted->end(); it2++)
        {
            if (*it1 < *it2)
            {
                sorted->insert(it2, *it1);
                break ;
            }
        }
        if (it2 == sorted->end())
            sorted->push_back(*it1);
    }
    return (sorted);
}

std::list<unsigned int>    *PmergeMe::mergeListInsertionSort()
{
    std::list<unsigned int> biggerElements, smallerElements;
    std::list<unsigned int> *sorted = new std::list<unsigned int>;
    for (listItr it = this->list_.begin(); it != this->list_.end(); it++)
    {
        unsigned int tmp = *it;
        it++;
        if (it == this->list_.end())
        {
            smallerElements.push_back(tmp);
            break ;
        }
        else if (tmp < *it)
        {
            biggerElements.push_back(*it);
            smallerElements.push_back(tmp);
        }
        else if (tmp >= *it)
        {
            biggerElements.push_back(tmp);
            smallerElements.push_back(*it);
        }
    }
    sorted = InsertionSort(sorted, biggerElements);
    sorted = InsertionSort(sorted, smallerElements);
    return (sorted);
}

void    PmergeMe::measureAndSort()
{
    std::cout << "Before: ";
    for (vecItr it = this->vector_.begin(); it != this->vector_.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    clock_t vecStart = clock();
    std::vector<unsigned int> *vectorSorted = mergeVectorInsertionSort();
    clock_t vecEnd = clock();
    clock_t listStart = clock();
    std::list<unsigned int> *listSorted = mergeListInsertionSort();
    clock_t listEnd = clock();

    std::cout << "Vector After: ";
    for (vecItr it = vectorSorted->begin(); it != vectorSorted->end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "List After: ";
    for (listItr it = listSorted->begin(); it != listSorted->end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << vectorSorted->size() << " elements with std::vector<unsigned int>: " << ((double)(vecEnd - vecStart) / CLOCKS_PER_SEC * 1000000) << " us" << std::endl;
    std::cout << "Time to process a range of " << listSorted->size() << " elements with std::list<unsigned int>: " << ((double)(listEnd - listStart) / CLOCKS_PER_SEC * 1000000) << " us" << std::endl;
    delete vectorSorted;
    delete listSorted;
}