#pragma once

#include <iostream>         //std::cout, std::cin
#include <iomanip>          //std::setprecision
#include <vector>           //std::vector, std::vector::push_back
#include <cctype>           //std::toupper

struct Calculation
{
    double n1;
    char op;
    double n2;
    double ans;
};

class Calculator
{
public:
    Calculator(const Calculator&) = delete;                 //Delete the copy constructor so that multiple instances of the singleton are not created
    static Calculator& get();                               //get function used to get single Singleton instance of Calculator class
    static void calculate() {return get().i_calculate();}   //Main member function, calls internal calculate function on the singleton instance

private:
    Calculation m_calc;                     //Struct of current calculation, holding n1, op, and n2 values for calculating + ans for answer value
    std::vector<Calculation> m_history;     //vector of calculation history
    inline static bool m_run;               //static flag to keep calculator while-loop running until [Q]uit
    static Calculator s_Instance;           //Singleton instance used for Calculator

private:
    Calculator() = default;                 //Default constructor, should not be called since Calculator is a Singleton
    void i_calculate();                     //Internal: Main member function that runs until Calculator object is destroyed
    void setAll();                          //sets n1, op, and n2 by calling setNum and setOp functions
    void setNum(double&);                   //sets Calculation n1 or n2 values, only excepts numbers
    void setOp(char&);                      //sets Calculation operator value, only excepts ('+' || '-' || '*' || '/')
    bool is_valid_op(const char&);          //returns true if char is an calculator operator ('+' || '-' || '*' || '/')
    void displayOperators();                //Displays operators to be used in calculator
    void displayAnswer() const;             //Displays "n1 op n2 =" and the answer of the calculation
    void displayHistory() const;            //Displays previous calculations
    void displayLine() const;               //prints a long "------" line to terminal, used for visual visibility
    void displayInfo() const;               //prints info about how calculator works
    void displayCommands() const;           //prints list of commands
    void startUp();                         //reset m_run flag to true, display calculator info
    void shutDown();                        //clear m_history and terminal
};