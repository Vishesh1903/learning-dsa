#include <iostream>
using namespace std;

class Fraction
{
    int numerator;
    int denominator;

public:
    Fraction()
    {
    }
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void add(const Fraction &f2)
    {
        this->numerator = f2.numerator * this->denominator + this->numerator * f2.denominator;
        this->denominator = f2.denominator * this->denominator;
        simplify();
    }

    int getNumerator() const
    {
        return numerator;
    }

    int getDenominator() const
    {
        return denominator;
    }
    void setNumerator(int numerator)
    {
        this->numerator = numerator;
    }
    void setDenominator(int denominator)
    {
        this->denominator = denominator;
    }

    void print()const 
    {
        cout << numerator << "/" << denominator << endl;
    }
    void simplify()
    {
        int gcd = 1;
        for (int i = 1; i <= min(numerator, denominator); i++)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                gcd = i;
            }
        }
        numerator /= gcd;
        denominator /= gcd;
    }
};

int main()
{
    const Fraction f3;

    cout << f3.getNumerator() << endl;
    cout << f3.getDenominator() << endl;

    // f3.setNumerator(10);

    return 0;
}