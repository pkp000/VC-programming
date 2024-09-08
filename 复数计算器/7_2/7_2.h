#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <sstream>
using namespace std;


class ComplexNumber
{
private:
    double realPart;
    double imaginaryPart;

public:
    ComplexNumber(double real, double imaginary) : realPart(real), imaginaryPart(imaginary) {}

    void add(ComplexNumber& other)
    {
        realPart += other.realPart;
        imaginaryPart += other.imaginaryPart;
    }

    void subtract(ComplexNumber& other)
    {
        realPart -= other.realPart;
        imaginaryPart -= other.imaginaryPart;
    }

    void multiply(ComplexNumber& other)
    {
        double newReal = realPart * other.realPart - imaginaryPart * other.imaginaryPart;
        double newImaginary = realPart * other.imaginaryPart + imaginaryPart * other.realPart;
        realPart = newReal;
        imaginaryPart = newImaginary;
    }

    void divide(ComplexNumber& other)
    {
        double denominator = other.realPart * other.realPart + other.imaginaryPart * other.imaginaryPart;
        if (denominator == 0) {
            throw "Division by zero is not allowed.";
        }
        double newReal = (realPart * other.realPart + imaginaryPart * other.imaginaryPart) / denominator;
        double newImaginary = (imaginaryPart * other.realPart - realPart * other.imaginaryPart) / denominator;
        realPart = newReal;
        imaginaryPart = newImaginary;
    }

    void print()
    {
        std::cout << "(" << realPart << "+" << imaginaryPart << "i)" << std::endl;
    }
};


int main();
void promptMessage();
void mutualInformation();
int calculateComplexNumber();
