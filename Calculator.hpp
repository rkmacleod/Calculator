#pragma once

#include <vector>       //std::vector

struct Calculation
{
    double n1;
    char op;
    double n2;
    double ans;
};

class Calculator
{
private:
    Calculation m_calc;                     //Struct of current calculation, holding n1, op, and n2 values for calculating + ans for answer value
    std::vector<Calculation> m_history;     //Dynamically allocated list of calculation history
    bool m_run;                             //flag to keep calculator while-loop

    void calculate();                       //Main member function that runs until Calculator object is destroyed
    void setAll();                          //sets n1, op, and n2 by calling setNum and setOp functions
    void setNum(double&);                   //sets Calculation n1 or n2 values, only excepts numbers
    void setOp(char&);                      //sets Calculation operator value, only excepts ('+' || '-' || '*' || '/')
    void listOperators();                   //Displays operators to be used in calculator
    bool is_valid_op(const char&);          //returns true if char is an calculator operator ('+' || '-' || '*' || '/')
    void displayAnswer() const;             //Displays "n1 op n2 =" and the answer of the calculation
    void displayHistory() const;            //Displays previous calculations
    void displayLine() const;               //prints a long "------" line to terminal, used for visual visibility
    void displayInfo();                     //prints info about how calculator works
    void displayCommands();                 //prints list of commands

public:
    Calculator();
    ~Calculator();
};