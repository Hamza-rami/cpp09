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
    size_t last_jacob = 0;
    size_t j = 2;

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
            std::vector<int>::iterator to_find = std::lower_bound(larger.begin(), larger.end(), pairs[i - 1].second);
            std::vector<int>::iterator it = std::lower_bound(larger.begin(), to_find, element_to_insert);

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

std::deque<int> fordJohnson(std::deque<int> array)
{
    std::deque<int> larger;
    std::deque<std::pair<int,int> > pairs;

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
    size_t last_jacob = 0;
    size_t j = 2;

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
            std::deque<int>::iterator to_find = std::lower_bound(larger.begin(), larger.end(), pairs[i - 1].second);
            std::deque<int>::iterator it = std::lower_bound(larger.begin(), to_find, element_to_insert);

            larger.insert(it, element_to_insert);
        }
        last_jacob = upper_bound;
        j++;
    }
    if (straggler != -1)
    {
        std::deque<int>::iterator it = std::lower_bound(larger.begin(), larger.end(), straggler);
        larger.insert(it, straggler);
    }
    return larger;
}


int parser(std::vector<int> &v, std::deque<int> &l, int ac, char const *av[])
{
    if (ac < 3)
        return (std::cout << "ERROR\n", 1);
    for (int i = 1; i < ac; i++)
    {
        int a;
        std::stringstream ss(av[i]);
        ss >> a;
        if (ss.fail() || !ss.eof())
        {
            std::cout << "ERROR: not number => " << av[i] << std::endl;
            return 1;
        }
        if (a < 0)
        {
            std::cout << "ERROR: only positive number => " << av[i] << std::endl;
            return 1;
        }
        v.push_back(a);
        l.push_back(a);
    }
    return 0;   
}


void sorting_printing(std::vector<int> &v, std::deque<int> &l)
{
    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i];
        if (v.size() - 1 != i)
            std::cout << " ";
    }
    std::cout << "\n";
    clock_t start = clock();
    v = fordJohnson(v);
    clock_t end = clock();
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
    clock_t start1 = clock();
    l = fordJohnson(l);
    clock_t end1 = clock();
    double elapsed1 = (double)(end1 - start1) / CLOCKS_PER_SEC * 1000000;
    std::cout << "After: ";
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i];
        if (v.size() - 1 != i)
            std::cout << " ";
    }
    std::cout << "\n";
    std::cout << "Time to process a range of " << v.size() << " elements with std::[vector] : " << elapsed << " us" << "\n";
    std::cout << "Time to process a range of " << l.size() << " elements with std::[deque] : " << elapsed1 << " us" << "\n";

}