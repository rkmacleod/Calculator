//#ifndef CALCUI_H
//#define CALCUI_H
#pragma once

#include <iostream>         //std::cout
#include <iomanip>          //std::setprecision
#include <algorithm>        //std::copy
#include <iterator>         //std::ostream_iterator
#include <vector>           //std::vector

#include "Calculation.hpp"


//used for output/menu interface
class CalcUI
{
public:
    CalcUI() {};
    ~CalcUI() {};
    void displayEnter();                                    //Prompts user to enter an expression or command
    void displayError();
    void displayOperators();                                //Displays operators to be used in calculator
    void displayAnswer(Calculation&);                       //Displays "n1 op n2 =" and the answer of the calculation
    void displayHistory(std::vector<Calculation>&);         //Displays previous calculations
    void displayLine();                                     //prints a long "------" line to terminal, used for visual visibility
    void displayInfo();                                     //prints info about how calculator works
    void displayCommands();                                 //prints list of commands
    void startUp();                                         //Display calculator info
    void shutDown();                                        //Clear screen and display shutting down
    void clearScreen();                                     //clears the terminal using ANSI Escape sequences
};

//#endif // CALCUI_H