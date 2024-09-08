#include"8_2.h"


// Deprecated in main() function
bool LargerPerfectNumber:: isPrime(long long n)
{
    if (n < 2)
        return false;

    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (long long i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

void LargerPerfectNumber:: pollardRhoFactorize(long long n)
{
    if (n == 1)
        return;

    if (isPrime(n))
    {
        factors[numberOfFactors++] = n;
        return;
    }

    long long p = n;
    while (p >= n) p = pollardRho(p);
    pollardRhoFactorize(p);
    pollardRhoFactorize(n / p);
}

long long LargerPerfectNumber:: pollardRho(long long n)
{
    long long x = rand() % n, y = x, c = rand() % n, u = 1, v, t = 0;
    for (long long i = 1, k = 2;; ++i)
    {
        x = (x * x + c) % n;
        
        if (x == y)
            return n;
       
        v = u;
        u = (long long)u * abs(y - x) % n;
        if (++t == k)
        {
            long long g = gcd(u, n);
           
            if (g > 1) 
                return g;

            y = x, u = v, k <<= 1;
        }
    }
}

LargerPerfectNumber::LargerPerfectNumber(int a ,long long num) : PerfectNumber(a)
{
    number = num;
    factors = new long long[num];
    numberOfFactors = 0;
    pollardRhoFactorize(num);
    sort(factors, factors + numberOfFactors);
    numberOfFactors = unique(factors, factors + numberOfFactors) - factors;
}

string LargerPerfectNumber:: getExpression()
{
    string expression = to_string(number) + " = ";
    bool first = true;
    for (long long i = 1; i < number; ++i)
    {
        if (number % i == 0)
        {
            if (!first) expression += " + ";
            expression += to_string(i);
            first = false;
        }
    }
    return expression;
}


long long gcd(long long a, long long b)
{
    while (b != 0) 
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


void lager10000() 
{
    for (long long i = 10000; i <= 1000000000000LL; i += 2)
    {
        LargerPerfectNumber* perfectNum = new LargerPerfectNumber(0,i);
        if (perfectNum->isPerfectNumber()) 
        {
            cout << perfectNum->getExpression() << endl;
        }
        delete perfectNum;
    }

}
