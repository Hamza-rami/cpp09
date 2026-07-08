#include "PmergeMe.hpp"

int main(int ac, char const *av[])
{
    std::vector<int> v;
    std::deque<int> l;
    if (parser(v, l, ac, av))
        return 1;
    sorting_printing(v, l);
}