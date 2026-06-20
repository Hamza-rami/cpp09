#include "PmergeMe.hpp"

int jacobsthal(size_t n)
{
    if (n == 0)
        return 0;
    if (n == 1)
    {
        return 1;
    }
    return jacobsthal(n-1) + 2 * jacobsthal(n-2);
}

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
    int first = larger[0];
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (first == pairs[i].second)
        {
            larger.insert(larger.begin(), pairs[i].first);
            break;
        }
    }
    size_t last_jacob = 1;
    size_t j = 3;

    while (last_jacob < pairs.size())
    {
        size_t curr_jacob = jacobsthal(j);
        
        size_t upper_bound = curr_jacob;
        if (upper_bound > pairs.size())
        {
            upper_bound = pairs.size();
        }

        for (size_t i = upper_bound; i > last_jacob; i--)
        {
            int element_to_insert = pairs[i - 1].first;

            std::vector<int>::iterator it = std::lower_bound(larger.begin(), larger.end(), element_to_insert);

            larger.insert(it, element_to_insert);
        }
        last_jacob = upper_bound;
        j++;
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