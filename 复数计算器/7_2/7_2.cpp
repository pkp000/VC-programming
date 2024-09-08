#include"7_2.h"


int main()
{
    
    
    do
    {
        calculateComplexNumber();
        mutualInformation();

    } while (true);
}


void mutualInformation()
{
    // Because this program has only one function, no additional specific exit events are set
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Calculate one more." << endl;
    cout << "(Mouse click Close or Alt+F4)\n" << endl;
}

void promptMessage()
{
    cout << "Please enter two complex and operator, such as (a+bi) operator (c+di)" << endl;
    cout << "No Spaces, such as :(5+3i)+(4+2i)" << endl << ":";
}

int calculateComplexNumber()
{
    string input;
    promptMessage();
    getline(cin, input);

    smatch matches;
    regex pattern("\\((-?\\d+\\.?\\d*)[+](-?\\d+\\.?\\d*)i\\)\\s*([+\\-*/])\\s*\\((-?\\d+\\.?\\d*)[+](-?\\d+\\.?\\d*)i\\)");
    if (regex_search(input, matches, pattern))
    {
        double real1 = stod(matches[1]);
        double imaginary1 = stod(matches[2]);
        double real2 = stod(matches[4]);
        double imaginary2 = stod(matches[5]);
        char operation = matches[3].str()[0];

        ComplexNumber num1(real1, imaginary1);
        ComplexNumber num2(real2, imaginary2);

        switch (operation)
        {
        case '+':
            num1.add(num2);
            break;
        case '-':
            num1.subtract(num2);
            break;
        case '*':
            num1.multiply(num2);
            break;
        case '/':
            try
            {
                num1.divide(num2);
            }
            catch (char* msg)
            {
                cerr << msg << endl;
                return 1;
            }
            break;
        default:
            cerr << "Invalid operator" << endl;
            return 1;
        }

        cout << "Eventuate = ";
        num1.print();
    }
    else
    {
        cerr << "Input format error!" << endl;
        return 1;
    }

    return 0;
}