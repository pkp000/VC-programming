#pragma once

#include"8_1.h"
#include <algorithm>
#include <cmath>
#include<string>


class LargerPerfectNumber :public PerfectNumber
{
    bool isPrime(long long n);

    void pollardRhoFactorize(long long n);

    long long pollardRho(long long n);

public:

    // Inherits the public part of the base class, like "number"¡¢"bool isPerfectNumber()"...

    LargerPerfectNumber(int a, long long num);

    string getExpression();

};


long long gcd(long long a, long long b);

void lager10000();