#include "BitcoinExchange.hpp"

int main(int ac, char const *av[])
{
    std::string line;
    std::map<std::string, float> price;
    if (ac != 2)
        return (std::cout << "Error: could not open file\n", 1);

    std::ifstream data("data.csv");
    if (!data.is_open()) 
    {
        std::cout << "Error: could not open file" << std::endl;
        return 1;
    }
    std::getline(data, line);
    while (std::getline(data, line))
    {
        size_t pos = line.find(",");
        if (pos != std::string::npos)
        {
            std::string date = line.substr(0, pos);
            ltrim(date);
            rtrim(date);
            std::string value = line.substr(pos + 1);
            ltrim(value);
            rtrim(value);
            price[date] = atof(value.c_str());
        }
    }

    std::ifstream file(av[1]);
    if (!file.is_open()) 
    {
        std::cout << "Error: could not open file" << std::endl;
        return 1;
    }
    int a = 0;
    while (std::getline(file, line))
    {
        if (line == "date | value" && !a)
        {
            a = 1;
            continue;
        }
        size_t pos = line.find("|");
        if (pos != std::string::npos)
        {
            std::string date = line.substr(0, pos);
            ltrim(date);
            rtrim(date);
            if(!check_date(date))
            {
                std::cout << "Error: bad input => " << date << std::endl;
                continue;
            }
            std::string value = line.substr(pos + 1);
            ltrim(value);
            rtrim(value);
            float val = check_value(value);
            if (val == -2 || val == -1)
            {
                std::cout << "Error: not a positive number.\n";
                continue;
            }
            else if (val == -3)
            {
                std::cout << "Error: too large a number.\n";
                continue;
            }
            std::map<std::string, float>::iterator it = price.lower_bound(date);
            if (it->first == date)
            {
                std::cout << date << " => " << val << " = " << val * it->second << std::endl;
            }
            else if(it == price.begin())
            {
                std::cout << "Error: no rate for this date.\n";
            }
            else
            {
                it--;
                std::cout << date << " => " << val << " = " << val * it->second << std::endl;
            }
        }
        else
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
    }
    
    return 0;
}
