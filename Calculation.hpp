#ifndef CALCULATION_H
#define CALCULATION_H
#pragma once

//holds calculation variables and calculates an answer
struct Calculation
{
    double n1 = 0;
    char op = '+';
    double n2 = 0;
    double ans = 0;
    double operator()();
    void operator=(const Calculation&); 
    bool is_valid_op();                 //returns true if char is an calculator operator ('+' || '-' || '*' || '/')
};

#endif // CALCULATION_H