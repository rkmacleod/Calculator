//#ifndef CALCULATOR_H
//#define CALCULATOR_H
#pragma once

#include <vector>           //std::vector, std::vector::push_back
#include <string>           //std::string, std::string::strtod(), std::getline
#include <iostream>         //std::cin
#include <sstream>          //

#include "Calculation.hpp"
#include "CalcUI.hpp"


//used for managing user input
class Calculator
{
public:
    Calculator() {};                            //Default constructor
    ~Calculator() {};                           //Default destructor
    void calculate();                           //Main member function that runs until Calculator object is destroyed

private:
    Calculation m_calc;                         //Struct of current calculation, holding n1, op, and n2 values for calculating + ans for answer value
    std::vector<Calculation> m_history;         //vector of calculation history
    std::string input;                          //string used to store user input, holds an expression or command
    CalcUI userInterface;                       //Class for outputting calculator UI, outputs to terminal
    bool m_run;                                 //flag to keep calculator while-loop running until [Q]uit

private:
    void setInput();
    void runInput();
    void parseExpression(const std::string&);
};

//#endif //CALCULATOR_H