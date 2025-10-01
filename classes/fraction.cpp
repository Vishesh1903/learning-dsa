#include <iostream>
using namespace std;

class Fraction
{
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void add (const Fraction &f2){
        this->numerator = f2.numerator* this->denominator + this->numerator*f2.denominator;
        this->denominator = f2.denominator * this->denominator;
        simplify();
    }

    void print()
    {
        cout << numerator << "/" << denominator << endl;

    }
    void simplify(){
        int gcd = 1;
        for (int i = 1; i <= min(numerator, denominator); i++){
            if (numerator % i == 0 && denominator % i == 0){
                gcd = i;
            }
        }
        numerator /= gcd;
        denominator /= gcd;
    }
};

int main()
{
    Fraction f1(3, 4);
    Fraction f2(5, 6);
    f1.add(f2);
    f1.print();
    return 0;
}