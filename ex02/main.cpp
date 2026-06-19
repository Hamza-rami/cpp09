#include "PmergeMe.hpp"

int main(int ac, char const *av[])
{
    std::vector<int> v;
    std::list<int> l;
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
    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i];
        if (v.size() - 1!= i)
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
        if (v.size() - 1!= i)
        std::cout << " ";
    }
    std::cout << "\n";
    std::cout << "Time to process a range of " << v.size() << " elements with std::[vector] : " << elapsed << " us" << "\n";
    std::cout << "Time to process a range of " << l.size() << " elements with std::[list] : " << elapsed1 << " us" << "\n";
}