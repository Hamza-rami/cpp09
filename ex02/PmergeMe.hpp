#pragma once


#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <utility>


std::vector<int> fordJohnson(std::vector<int> array);
std::deque<int> fordJohnson(std::deque<int> array);
int parser(std::vector<int> &v, std::deque<int> &l, int ac, char const *av[]);


void sorting_printing(std::vector<int> &v, std::deque<int> &l);