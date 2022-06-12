#include "Calculation.hpp"

double Calculation::operator()()
{
    switch(op)
    {
        case '+':
            ans = n1 + n2;
            break;
        case '-':
            ans = n1 - n2;
            break;
        case '*':
            ans = n1 * n2;
            break;
        case '/':
            if(n2 != 0)
                ans = n1 /n2;
            else ans = 0;
            break; 
    }
    return ans;
}

void Calculation::operator=(const Calculation& expression)
{
    this->n1 = expression.n1;
    this->op = expression.op;
    this->n2 = expression.n2;
    this->ans = expression.ans;
}

bool Calculation::is_valid_op()
{
    return op == '+'
        || op == '-'
        || op == '*'
        || op == '/';
}