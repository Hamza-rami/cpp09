#include "BitcoinExchange.hpp"

int main(int ac, char const *av[])
{
    std::string line;
    std::map<std::string, float> price;
    
    if (laod_data(price, ac))
        return 1;
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
            if (a == 0)
                return (std::cout << "First line should be 'date | value'\n", 1);
            process_line(line, price, pos);
        }
        else
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
    }
    
    return 0;
}
