#include"6_2.h"


int countingUnit = 1;
int itemNum, *pN = &itemNum;
double sum, x, *px = &x;
double commonRatio, *pRatio = &commonRatio;


double sumGeometricProgression(double currentItem)
{
	if (countingUnit > itemNum)
	{
		return sum;
	}

	sum += currentItem;
	countingUnit++;
    currentItem *= commonRatio;

	return sumGeometricProgression(currentItem);
}

void taylorSeriesMutualInformation()
{
    countingUnit = 1;
    sum = 0;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "( Note that if you want Taylor to expand correctly make sure x > 1 )" << endl;
	cout << "Please enter the number of terms to calculate for the Taylor series:" << endl;
	cout << "itemNum = ";
	cin >> *pN;
	cout << "S = 1 + (1/x) + (1/x)^2 + (1/x)^3 + ... " << endl;
	cout << "x = ";
	cin >> *px;
	*pRatio = 1.0 / x;
}

void proportionalSeriesMutualInformation()
{
    double firstTerm;
    countingUnit = 1;
    sum = 0;
    cout << "____________________________________________________________________" << endl;
    cout <<"The number of terms to calculate = " ;
    cin >> *pN;
    cout << "The first term = ";
    cin >> firstTerm;
    cout << "common ratio of a geometric series = ";
    cin >> *pRatio;
    cout << "S = " << sumGeometricProgression(firstTerm) << endl;
    cout << "____________________________________________________________________" << endl;
}

void mutualInformation2()
{
    cout << "Please select an option(1-3) £º" << endl;
    cout << "1. Calculate [1/(1-1/x)] Taylor series summation" << endl;
    cout << "2. Calculate summations of other geometric series" << endl;
    cout << "(Enter 3 to exit)" << endl;
}

void f2()
{
    int choice;
    cout << "\n\t<<The second question>>" << endl;

    do
    {
        mutualInformation2();
        cin >> choice;

        switch (choice)
        {
        case 1:
            taylorSeriesMutualInformation();
            cout << "S = " << sumGeometricProgression(1) << endl;
            cout << "--------------------------------------------------------------------" << endl;
            break;

        case 2:
            proportionalSeriesMutualInformation();
            break;

        case 3:
            // Have practical significance
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (choice != 3);
}
