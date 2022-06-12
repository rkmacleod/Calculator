//Basic calculator in C++ that can perform addition, subtraction, multiplication, and division for ints and doubles
#include "Calculator.hpp"   //Calculator class, Calculation struct        

void Calculator::calculate()
{
    m_run = true;                   //reset m_run if reusing calculator object
    userInterface.startUp();

    while(m_run == true)        //run calculations until [Q]uit is called
    {
        setInput();        //prompt user for n1, op, and n2 values
        runInput();
    }

    userInterface.shutDown();
    m_history.clear();      //clear Calculation vector history
}

void Calculator::setInput()
{
    userInterface.displayEnter();           //ask user for input

    if(!std::getline(std::cin, input))      //if error while reading input
    {
        userInterface.displayError();       //display error message
    }
}

void Calculator::runInput()
{
    if((input == "Q") || (input == "q"))        //if Q was entered, shut down calculator
    {
        m_run = false;                      //set run flag to false for calculate do-while-loop
    }
    else if((input == "H") || (input == "h"))   //if H was entered, display calculation history
    {
        userInterface.displayHistory(m_history);
    }
    else if((input == "C") || (input == "c"))   //if C was entered, display commands list
    {
        userInterface.displayCommands();
    }
    else
        parseExpression(input);              //if input is not a command, parse input string 
}

void Calculator::parseExpression(const std::string& expression)
{
    std::stringstream ss(expression);
    Calculation temp;                   //temporary calculation used to store expression values before validating

    ss >> temp.n1 >> temp.op >> temp.n2;

    if((!ss) || (!temp.is_valid_op()))  //if invalid expression or invalid operator
    {
        userInterface.displayError();
    }
    else    //If a correct expression
    {
        temp();
        m_calc = temp;
        userInterface.displayAnswer(m_calc);    //display calc + ans on terminal
        m_history.push_back(m_calc);            //add calculation to history
    }
}