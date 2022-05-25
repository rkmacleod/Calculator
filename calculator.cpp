//Basic calculator in C++ that can perform addition, subtraction, multiplication, and division for ints and doubles
#include "Calculator.hpp"   //Calculator class, Calculation struct        

Calculator& Calculator::get()
{
    static Calculator s_Instance;
    return s_Instance;
}

void Calculator::i_calculate()
{
    startUp();

    while(s_run == true)    //run calculations until [Q]uit is called
    {
        setAll();           //prompt user for n1, op, and n2 values

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

        if(s_run == true)
        {
            displayAnswer();                //display calc + ans on terminal
            m_history.push_back(m_calc);    //add calculation to history
        }
    }

    shutDown();
}

void Calculator::setAll()
{
    std::cout << "Enter first number: ";
    setNum(m_calc.n1);

    if(s_run == true)
    {
        displayOperators();
        std::cout << "Enter operation: ";
        setOp(m_calc.op);
    }

    if(s_run == true)
    {  
        std::cout << "Enter second number: ";
        setNum(m_calc.n2);
    }
}

void Calculator::setNum(double& n)
{
    std::string input;      //string for testing if input is a double or char
    char* c_ptr = nullptr;  //char pointer, will point to first char that cannot be converted to a double

    do
    {
        std::cin >> input;                              //get user input as a string
        double d_test = strtod(input.c_str(), &c_ptr);  //test if string is a double by using strtod. If double, c_ptr == nullptr
        if(*c_ptr == 0)                                 //if a double
        {
            n = d_test;     //set n to double
            break;          //break do-while loop
        }
        else if(input.length() == 1)        //if string is only a char
        {
            if(is_valid_command(*c_ptr))    //if the char is a command
            {
                command(*c_ptr);            //implement command
                if(s_run == false)          //if command was [Q]uit
                    break;                  //break do-while loop
            }
        }
        else    //Invalid input: not a double or a command char
        {
            std::cout << "Error: not a number" << std::endl;
            std::cin.clear();                                   //clears the error flag on cin
            std::cin.ignore(256, '\n');                         //skip to the next new line
        }

        std::cout << "Enter number: ";                          //ask for new number

    } while (true);
}

void Calculator::setOp(char& ch)
{
    do
    {
        std::cin >> ch;
        if(is_valid_command(ch))        //check if char is a command
            command(ch);                //if a command, implement command
        else if(!(is_valid_op(ch)))                             //check if ch is an operator char (+,-,*,/)
        {
            std::cout << "Error: not an operator" << std::endl;
            std::cin.clear();                                   //clears the error flag on cin
            std::cin.ignore(256, '\n');                         //skip to the next new line
        }
        else break;                                             //end do-while loop once a valid char has been entered

        std::cout << "Enter operation: ";                       //ask for new operator

    } while (true);  
}

bool Calculator::is_valid_command(const char& ch)
{
    return (std::toupper(ch) == 'Q')
        || (std::toupper(ch) == 'H')
        || (std::toupper(ch) == 'C');
}

bool Calculator::is_valid_op(const char& ch)
{
    return ch == '+'
        || ch == '-'
        || ch == '*'
        || ch == '/';
}

void Calculator::command(const char& ch)
{
    if(std::toupper(ch) == 'Q')                             //if Q was entered, shut down calculator
    {
        s_run = false;                                      //set run flag to false for calculate do-while-loop
    }
    else if(std::toupper(ch) == 'H')                        //if H was entered, display calculation history
        displayHistory();
    else if(std::toupper(ch) == 'C')                        //if C was entered, display commands list
        displayCommands();
}

void Calculator::displayOperators() const
{
    std::cout << "Addition: + | Subtraction: - | Multiplication: * | Division: /" << std::endl;
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

void Calculator::displayInfo() const
{
    std::cout << "Terminal controllable calculator that does (+,-,*,/) operations and holds a history of calculations" << std::endl;
}

void Calculator::displayCommands() const
{
    std::cout << "Commands: [Q]uit, [H]istory, [C]ommands" << std::endl;
}

void Calculator::startUp()
{
    std::cout << "Calculator starting up..." << std::endl;
    displayInfo();
    displayCommands();
    s_run = true;                   //reset s_run if reusing calculator object
    std::cout.precision(16);        //set precision to 16 decimal places max
}

void Calculator::shutDown()
{
    m_history.clear();      //clear Calculation vector history
    system("clear");        //clear terminal
    std::cout << "Calculator shutting down..." << std::endl;
}