#include "RPN.hpp"

int main(int ac, char *av[])
{
    if(ac != 2)
        return (std::cerr << "Error: expected exactly one argument\n", 1);
    rpn_logic(av);
}
