#pragma once


#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <sstream>
#include <utility>


std::vector<int> fordJohnson(std::vector<int> array);
std::list<int> fordJohnson(std::list<int> array);
int parser(std::vector<int> &v, std::list<int> &l, int ac, char const *av[]);


void sorting_printing(std::vector<int> &v, std::list<int> &l);