//Basic calculator in C++ that can perform addition, subtraction, multiplication, and division for ints and doubles
#include "Calculator.hpp"   //Calculator class, Calculation struct
#include <iostream>         //std::cout, std::cin
#include <iomanip>          //std::setprecision
#include <vector>           //std::vector, std::vector::push_back

Calculator::Calculator()
    : m_calc({0,'+', 0, 0}), m_run(true)
{
    std::cout << "Calculator starting up..." << std::endl;
    displayInfo();
    displayCommands();
    std::cout.precision(16);        //set precision to 16 decimal places max
    calculate();                    //Run calculation program until [Q]uit is called
}

Calculator::~Calculator()
{
    system("clear");
    std::cout << "Calculator shutting down..." << std::endl;
}

void Calculator::calculate()
{
    while(m_run == true)    //run calculations until [Q]uit is called
    {
        setAll();   //prompt user for n1, op, and n2 values

        switch(m_calc.op)
        {
            case '+':
                m_calc.ans = m_calc.n1 + m_calc.n2;
                break;
            case '-':
                m_calc.ans = m_calc.n1 - m_calc.n2;
                break;
            case '*':
                m_calc.ans = m_calc.n1 * m_calc.n2;
                break;
            case '/':
                if(m_calc.n2 != 0)
                    m_calc.ans = m_calc.n1 / m_calc.n2;
                else m_calc.ans = 0;
                break; 
        }

        displayAnswer();                //display calc + ans on terminal
        m_history.push_back(m_calc);    //add calculation to history
    }
}

void Calculator::setAll()
{
    std::cout << "Enter first number: ";
    setNum(m_calc.n1);

    listOperators();
    std::cout << "Enter operation: ";
    setOp(m_calc.op);

    std::cout << "Enter second number: ";
    setNum(m_calc.n2);
}

void Calculator::setNum(double& n)
{
    do
    {
        if(!(std::cin >> n))
        {
            std::cout << "Error: not a number" << std::endl;
            std::cin.clear();                                   //clears the error flag on cin
            std::cin.ignore(256, '\n');                         //skip to the next new line
        }
        else break;                                             //break if n has been set to a number

        std::cout << "Enter number: ";                          //ask for new number

    } while (true);
}

void Calculator::setOp(char& op)
{
    do
    {
        std::cin >> op;
        if((op == 'Q') || op == 'q')                            //if Q was entered, shut down calculator
        {
            m_run = false;                                      //set run flag to false for calculate do-while-loop
            break;                                              //break out of setNum
        }
        else if((op == 'H') || (op == 'h'))                     //if H was entered, display calculation history
            displayHistory();
        else if((op == 'C') || (op == 'c'))                     //if C was entered, display commands list
            displayCommands();
        else if(!(is_valid_op(op)))                             //check if op is an operator char (+,-,*,/)
        {
            std::cout << "Error: not an operator" << std::endl;
            std::cin.clear();                                   //clears the error flag on cin
            std::cin.ignore(256, '\n');                         //skip to the next new line
        }
        else break;                                             //end do-while loop once a valid char has been entered

        std::cout << "Enter operation: ";                       //ask for new operator

    } while (true);  
}

void Calculator::listOperators()
{
    std::cout << "Addition: + | Subtraction: - | Multiplication: * | Division: /" << std::endl;
}

bool Calculator::is_valid_op(const char& ch)
{
    return ch == '+'
        || ch == '-'
        || ch == '*'
        || ch == '/';
}

void Calculator::displayAnswer() const
{
    system("clear");    //clear the terminal before displaying answer
    displayLine();
    std::cout << m_calc.n1 << " " << m_calc.op << " " << m_calc.n2 << " =" << std::endl;
    std::cout << m_calc.ans << std::endl; 
    displayLine();
}

void Calculator::displayHistory() const
{
    displayLine();

    if(m_history.empty())
        std::cout << "No calculations have been done yet." << std::endl;
    else
    {
        for (const Calculation& struct_i : m_history)       //ranged-based for-loop, iterate over each Calculation struct
        {
            std::cout << struct_i.n1 << " " << struct_i.op << " " << struct_i.n2 << " =" << std::endl;
            std::cout << struct_i.ans << std::endl;
            displayLine();
        }
    }
}

void Calculator::displayLine() const
{
    std::cout << "--------------------------------------------" << std::endl;
}

void Calculator::displayInfo()
{
    std::cout << "Terminal controllable calculator that does (+,-,*,/) operations and holds a history of calculations" << std::endl;
}

void Calculator::displayCommands()
{
    std::cout << "Commands: [Q]uit, [H]istory, [C]ommands" << std::endl;
}