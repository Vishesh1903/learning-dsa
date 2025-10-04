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

    Fraction add(const Fraction &f2)
    {
        const int num = f2.numerator * this->denominator + this->numerator * f2.denominator;
        const int denom = f2.denominator * this->denominator;

        Fraction fnew(num, denom);
        fnew.simplify();
        return fnew;
    }
    Fraction& operator+(const Fraction &f2)const
    {
        const int num = f2.numerator * this->denominator + this->numerator * f2.denominator;
        const int denom = f2.denominator * this->denominator;

        Fraction* fnew=  new Fraction(num, denom);
        fnew->simplify();
        return *fnew;
    }

    Fraction& operator++(){
        this->numerator = this->numerator + this->denominator;
        this->simplify();
        return *this;

    }

    Fraction operator++(int){
        Fraction temp = *this;
        this->numerator = this->numerator + this->denominator;
        this->simplify();
        return temp;
    }

    Fraction operator+= (const Fraction& f2){
        *this = *this + f2;
        return *this;
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
    Fraction f1(3, 4);
    Fraction f2(5, 6);
    Fraction f3 = f1.add(f2);
    Fraction f4 = f1 + f2;
    f4.print();
    f3.print();
    f1.print();
    f2.print();

    Fraction f5(6, 8);
    Fraction f6 = ++(++f5);
    f5.print();
    f6.print();

    Fraction f7(6, 1);
    Fraction f8 = f7++;
    f7.print();
    f8.print();

    f8+=f7;
    f8.print();

    
    return 0;
}