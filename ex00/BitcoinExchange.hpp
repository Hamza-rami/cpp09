#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>

void rtrim(std::string &s);
void ltrim(std::string &s);
bool check_format(std::string &str);
bool is_valid(std::string &str);
bool check_date(std::string &str);
float check_value(std::string &str);
int laod_data(std::map<std::string, float> &price, int ac);
void process_line(std::string line, std::map<std::string, float> &price, int pos);