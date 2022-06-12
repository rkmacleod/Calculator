#include "CalcUI.hpp"

//Stream inserter to print out a Calculation
std::ostream& operator<<(std::ostream& out, const Calculation& calc)
{
    return out << calc.n1 << " " << calc.op << " " << calc.n2 << " =\n"
        << calc.ans << "\n--------------------------------------------";
}

void CalcUI::displayEnter()
{
    std::cout << "Enter a command or an expression:\n";
}

void CalcUI::displayError()
{
    std::cout << "Error: not a valid expression or command\n";
}

void CalcUI::displayOperators()
{
    std::cout << "Addition: + | Subtraction: - | Multiplication: * | Division: /\n";
}

void CalcUI::displayAnswer(Calculation& calc)
{
    clearScreen();      //clear the terminal before displaying answer
    displayLine();
    std::cout << calc << "\n";
}

void CalcUI::displayHistory(std::vector<Calculation>& history)
{
    displayLine();
    if(history.empty())
        std::cout << "No calculations have been done yet.\n";
    else
    {
        std::copy(history.begin(), history.end(), std::ostream_iterator<Calculation>(std::cout, "\n"));
    }
}

void CalcUI::displayLine()
{
    std::cout << "--------------------------------------------\n";
}

void CalcUI::displayInfo()
{
    std::cout << "Terminal controllable calculator that does (+,-,*,/) operations and holds a history of calculations\n";
}

void CalcUI::displayCommands()
{
    std::cout << "Commands: [Q]uit, [H]istory, [C]ommands\n";
}

void CalcUI::startUp()
{
    std::cout << "Calculator starting up...\n";
    displayInfo();
    displayCommands();
    std::cout.precision(16);        //set precision to 16 decimal places max
}

void CalcUI::shutDown()
{
    clearScreen();          //clear terminal
    std::cout << "Calculator shutting down...\n";
}

void CalcUI::clearScreen()
{
    //std::cout << "\x1B[2J";
    system("clear");
}