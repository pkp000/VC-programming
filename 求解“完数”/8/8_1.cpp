#include"8_1.h"


long long PerfectNumber::getNumber() 
{
    return number;
}

long long* PerfectNumber::getFactors()
{
    return  factors;
}

int PerfectNumber::getFactorCount()
{
    return numberOfFactors;
}

PerfectNumber::PerfectNumber(int num)
{
    number = num;

    // According to mathematical principles, when number > 4
    int maxNumberFactors = int(sqrt(number));

    factors = new long long[number / 2]; // Dynamically allocated memory
    
    numberOfFactors = 0;

    for (int i = 1; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            factors[numberOfFactors++] = i;
        }
    }
}

PerfectNumber::~PerfectNumber()
{
    delete[] factors; // Free dynamically allocated memory
}

bool PerfectNumber:: isPerfectNumber()
{
    int sum = 0;
    for (int i = 0; i < numberOfFactors; i++)
    {
        sum += factors[i];
    }

    if (sum == number)
    {
        return true;
    }

    else
    {
        return false;
    }
}

void PerfectNumber::visualDisplay()
{
    cout << number << " = ";

    int i = 0;
    int notFinished = numberOfFactors - 1;
   
    do
    {
        cout << factors[i];

        if (i != notFinished)
        {
            cout << " + ";
        }

        i++;

    } while (i < numberOfFactors);

    cout << endl;
}


void welcome()
{
    cout << "\t\tWelcome!" << endl;
    cout << "Perfect numbers are perfect.We can find some of them:" << endl;
}

void goodbye()
{
    
    cout << "Enter any key to exit..." << endl;
    cin.ignore();
    cin.get();
}




// Function overload
void within10000(int n) 
{   
    // Find out the complete number in the variable size range "n"
    // The efficiency "n" should not exceed 50,000
    for (int i = 1; i <= n; i++)
    {
        PerfectNumber* perfectNumber = new PerfectNumber(i); // Dynamically create object

        if (perfectNumber->isPerfectNumber())
        {
            perfectNumber->visualDisplay();
        }

        delete perfectNumber; // Releases dynamically created objects
    }
}


void within10000()
{
    // If you try to find the "perfect numbers" 33550336 and 8589869056 in this way, it is very time consuming
    // for (long long i = 1; i <= 1000000000000LL; i++)

    for (int i = 1; i <= 10000; i++)
    {
        PerfectNumber* perfectNumber = new PerfectNumber(i);
        if (perfectNumber->isPerfectNumber())
        {
            perfectNumber->visualDisplay();
        }

        delete perfectNumber;
    }
}


