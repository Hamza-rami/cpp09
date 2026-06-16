#include "PmergeMe.hpp"

std::vector<int> fordJohnson(std::vector<int> array)
{
    std::vector<int> larger;
    std::vector<std::pair<int,int> > pairs;

    if (array.size() <= 1)
        return array;

    int straggler = -1; 
    if (array.size() % 2 != 0)
        straggler = array[array.size() - 1];
    
    for (size_t i = 0; i + 1 < array.size(); i += 2)
    {
        if (array[i] > array[i+1])
        {
            std::swap(array[i], array[i+1]);
        }
        pairs.push_back(std::make_pair(array[i], array[i+1]));
    }

    for (size_t i = 0; i < pairs.size(); i++)
    {
        larger.push_back(pairs[i].second);
    }

    larger = fordJohnson(larger);
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::vector<int>::iterator it = std::lower_bound(larger.begin(), larger.end(), pairs[i].first);
        larger.insert(it, pairs[i].first);
    }
    if (straggler != -1)
    {
        std::vector<int>::iterator it = std::lower_bound(larger.begin(), larger.end(), straggler);
        larger.insert(it, straggler);
    }
    return larger;
}


std::list<int> fordJohnson(std::list<int> array)
{
    std::list<int> larger;
    std::list<std::pair<int,int> > pairs;

    if (array.size() <= 1)
        return array;

    int straggler = -1; 
    if (array.size() % 2 != 0)
        straggler = array.back();
    
    std::list<int>::iterator it = array.begin();
    while (it != array.end())
    {
        std::list<int>::iterator first = it;
        ++it;
        if (it == array.end()) 
            break;
        std::list<int>::iterator second = it;
        ++it;
        if (*first > *second)
        {
            std::swap(*first, *second);
        }
        pairs.push_back(std::make_pair(*first, *second));
    }

    for (std::list<std::pair<int,int> >::iterator it = pairs.begin(); it !=  pairs.end(); it++)
    {
        larger.push_back(it->second);
    }

    larger = fordJohnson(larger);
    for (std::list<std::pair<int,int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        std::list<int>::iterator pos = std::lower_bound(larger.begin(), larger.end(), it->first);
        larger.insert(pos, it->first);
    }
    if (straggler != -1)
    {
        std::list<int>::iterator it = std::lower_bound(larger.begin(), larger.end(), straggler);
        larger.insert(it, straggler);
    }
    return larger;
}