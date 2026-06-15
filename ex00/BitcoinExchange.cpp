#include "BitcoinExchange.hpp"


void rtrim(std::string &s) 
{
    size_t end = s.find_last_not_of(" ");
    if (end != std::string::npos) {
        s.erase(end + 1);
    } else {
        s.clear();
    }
}

void ltrim(std::string &s) 
{
    size_t start = s.find_first_not_of(" ");
    s.erase(0, start);
}

float check_value(std::string &str)
{
    std::stringstream ss(str);
    float val;
    ss >> val;
    if (ss.fail() || !ss.eof())
    {
        return -1;
    }
    if (val < 0)
        return -2;
    else if (val > 1000)
        return -3;
    return val;
}

bool check_format(std::string &str)
{
    if (str.size() != 10)
        return false;
    if (str[4] != '-' || str[7] != '-')
        return false;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]) && str[i] != '-')
        {
            return false;
        }
    }
    return true;
}

bool is_valid(std::string &str)
{
    int arr[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    int year = atoi(str.substr(0,4).c_str());
    int month = atoi(str.substr(5,2).c_str());
    int day = atoi(str.substr(8,2).c_str());
    if (month > 12 || month < 1)
        return false;
    if (day < 1 || day > arr[month-1])
        return false;
    (void)year;
    return true;
}

bool check_date(std::string &str)
{
    if (!check_format(str))
        return false;
    if (!is_valid(str))
        return false;
    return true;
}