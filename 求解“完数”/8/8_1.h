#pragma once

#include <iostream>


using namespace std;


class PerfectNumber
{
public:
    // Subsequent inheritance and modification, so written in public
    // To facilitate further discussion of larger numbers, the long long type is used here
    long long number; 
    long long* factors;
    int numberOfFactors;


    PerfectNumber(int num); // constructor
    ~PerfectNumber(); // destructor


    long long getNumber();
    long long* getFactors();
    int getFactorCount();


    void visualDisplay();

    bool isPerfectNumber();

};

void welcome();
void goodbye();
void within10000();
void within10000(int n);
