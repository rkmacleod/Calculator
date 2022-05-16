//Basic calculator in C++ that can perform addition, subtraction, multiplication, and division for ints and doubles
#include <iostream>     //std::cout, std::cin
#include <iomanip>      //std::setprecision
#include <cctype>       //std::toupper()

//Function Declarations
void listCommands();                                    //List calculator commands
void getNums(double&, double&);                         //get input numbers
double addition(const double&, const double&);
double subtraction(const double&, const double&);
double multiplication(const double&, const double&);
double division(const double&, const double&);

int main()
{
    double n1, n2;
    char command;
    std::cout.precision(16);    //set precision to 16 decimal places max


    std::cout << "Calculator starting up...\n";
    listCommands();
    std::cout << std::endl;

    do
    {
        std::cout << "Enter command: ";
        std::cin >> command;

        if(std::toupper(command) == 'A')
        {
            std::cout << "\nAddition has been selected.\n";
            getNums(n1, n2);
            std::cout << n1 << " + " << n2 << " = " << addition(n1, n2) << std::endl;
        }
        else if(std::toupper(command) == 'S')
        {
            std::cout << "\nSubtraction has been selected.\n";
            getNums(n1, n2);
            std::cout << n1 << " - " << n2 << " = " << subtraction(n1, n2) << std::endl;
        }
        else if(std::toupper(command) == 'M')
        {
            std::cout << "\nMultiplication has been selected.\n";
            getNums(n1, n2);
            std::cout << n1 << " * " << n2 << " = " << multiplication(n1, n2) << std::endl;
        }
        else if(std::toupper(command) == 'D')
        {
            std::cout << "\nDivision has been selected.\n";
            getNums(n1, n2);

            //Exception: n2 cannot = 0
            try
            {
                if(n2 == 0)
                {
                    throw "Error: can't divide a number by zero";
                }
                std::cout << n1 << " / " << n2 << " = " << division(n1, n2) << std::endl;
            }
            catch(const char* ex) 
            {
                std::cout << ex << std::endl;
            }

            
        }
        else if(std::toupper(command) == 'H')
        {
            listCommands();
        }
        else if(std::toupper(command) != 'Q')
        {
            std::cout << "Error: invalid command.\n";
        }

        std::cout << std::endl;

    } while (std::toupper(command) != 'Q');
    
    std::cout << "Calculator shutting down...\n";
}

void getNums(double& n1, double& n2)
{
    do
    {
        std::cout << "Enter first number: ";
        if(!(std::cin >> n1))
        {
            std::cout << "Error: not a number" << std::endl;
            std::cin.clear();                                   //clears the error flag on cin
            std::cin.ignore(256, '\n');                         //skip to the next new line
        }
        else break;                                             //break once a number has been entered
        
    } while (true);
    
    do
    {
        std::cout << "Enter second number: ";
        if(!(std::cin >> n2))
        {
            std::cout << "Error: not a number" << std::endl;
            std::cin.clear();                                   //clears the error flag on cin
            std::cin.ignore(256, '\n');                         //skip to the next new line
        }
        else break;                                             //break once a number has been entered
        
    } while (true);
}

void listCommands()
{
    std::cout << "\nAddition: 'A'\nSubtraction: 'S'\nMultiplication: 'M'\nDivision: 'D'\nHelp: 'H'\nQuit: 'Q'\n";
}

double addition(const double& n1, const double& n2)
{
    return n1 + n2;
}

double subtraction(const double& n1, const double& n2)
{
    return n1 - n2;
}

double multiplication(const double& n1, const double& n2)
{
    return n1 * n2;
}

double division(const double& n1, const double& n2)
{  
    return n1 / n2;
}