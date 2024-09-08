#include"6_1.h"


float a0 = 3;
float b0 = 2;
float c0 = 0;
float d0 = 1;

float* pa0, * pb0, * pc0, * pd0;
float a, b, c, d;

void cubicFunctionParameterModify()
{
	pa0 = &a0;
	pb0 = &b0;
	pc0 = &c0;
	pd0 = &d0;

	// Function nested call
	parameterModifyPromptMessage();

	cout << "\ta = ";
	cin >> a;
	cout << "\tb = ";
	cin >> b;
	cout << "\tc = ";
	cin >> c;
	cout << "\td = ";
	cin >> d;

	*pa0 = a;
	*pb0 = b;
	*pc0 = c;
	*pd0 = d;

	// Show the parameters of the current cubic function after modification
	cout << "f1(x) = " << a0 << " * x^3 + " << b0 << " * x^2 + " << c0 << " * x + " << d0 << endl;
	cout << "------------------------------------------------" << endl;
}

void parameterModifyPromptMessage()
{
	cout << "\n------------------------------------------------" << endl;
	cout << "f1(x) = a * x^3 + b * x^2 + c * x + d" << endl;
	cout << "You can modify the parameters(a,b,c,d):" << endl;
}

float calculateCubicFunction()
{
	float x, y;
	cout << "\n***********************************************" << endl;
	cout << "x = ";
	cin >> x;
	y = a0 * pow(x, 3) + b0 * pow(x, 2) + c0 * x + d0;
	return y;
}

void  displayResult(float y)
{
	
	cout << "f1(x) = " << a0 << " * x^3 + " << b0 << " * x^2 + " << c0 << " * x + " << d0 << " = " << y << endl;
	cout << "***********************************************\n" << endl;
}


void mutualInformation1()
{
	cout << "Please select an option(1-3) £º" << endl;
	cout << "1.Calculate function directly\n2.Modify a cubic function parameter" << endl;
	cout << "(Enter 3 to exit)" << endl;
}

void f1()
{
	float result;
	int choice;
	cout << "\t<<The first question>>" << endl;

	do
	{
		mutualInformation1();
		cin >> choice;

		// Design function branch
		switch (choice)
		{
		case 1:
			cout << "You chose: 1.Calculate function directly" << endl;
			cout << "f1(x) = " << a0 << " * x^3 + " << b0 << " * x^2 + " << c0 << " * x + " << d0 << endl;
			result = calculateCubicFunction();
			displayResult(result);
			break;

		case 2:
			cout << "You chose: 2.Modify a cubic function parameter" << endl;
			cubicFunctionParameterModify();
			break;

		case 3:
			// Have practical significance
			break;

		default:
			// Code that handles invalid options
			cout << "Invalid option! -- reenter\n" << endl;
			break;
		}
	} while (choice != 3);
}
