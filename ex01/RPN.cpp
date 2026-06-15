#include "RPN.hpp"


int rpn_logic(char **av)
{
    std::stack<long long> rpn;
    long long res;

    for (int i = 0; av[1][i]; i++)
    {
        if (isdigit(av[1][i]))
        {
            rpn.push(av[1][i] - '0');
        }
        else if(av[1][i] == '+')
        {
            if(rpn.size() < 2)
                return (std::cerr << "Error: insufficient operands\n", 1);
            long long right = rpn.top();
            rpn.pop();
            long long left = rpn.top();
            rpn.pop();
            res = left + right;
            rpn.push(res);
        }
        else if(av[1][i] == '*')
        {
            if(rpn.size() < 2)
                return (std::cerr << "Error: insufficient operands\n", 1);
            long long right = rpn.top();
            rpn.pop();
            long long left = rpn.top();
            rpn.pop();
            res = left * right;
            rpn.push(res);
        }
        else if(av[1][i] == '-')
        {
            if(rpn.size() < 2)
                return (std::cerr << "Error: insufficient operands\n", 1);
            long long right = rpn.top();
            rpn.pop();
            long long left = rpn.top();
            rpn.pop();
            res = left - right;
            rpn.push(res);
        }
        else if(av[1][i] == '/')
        {
            if(rpn.size() < 2)
                return (std::cerr << "Error: insufficient operands\n", 1);
            long long right = rpn.top();
            rpn.pop();
            long long left = rpn.top();
            rpn.pop();
            if (right == 0)
                return (std::cerr << "Error: division by zero\n", 1);
            res = left / right;
            rpn.push(res);
        }
        else if(av[1][i] == ' ')
            continue;
        else
            return (std::cerr << "Error: invalid character '" << av[1][i] << "'\n", 1);
    }

    if(rpn.size() !=  1)
        return (std::cerr << "Error: invalid RPN expression\n", 1);
    std::cout << rpn.top() << std::endl;
    
    return 0;
}