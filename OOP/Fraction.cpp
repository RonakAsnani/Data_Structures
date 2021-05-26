#include <iostream>
#include<algorithm>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denomenator;

public:
    Fraction(){

    };

    Fraction(int numerator, int denomenator)
    {
        this->numerator = numerator;
        this->denomenator = denomenator;
    };

    int getNumerator() const
    {
        return numerator;
    }
    int getDenomenator() const
    {
        return denomenator;
    }
    void setnum(int n)
    {
        numerator = n;
    }
    void setden(int d)
    {
        denomenator = d;
    }

    void print() const
    {
        cout << this->numerator << "/" << denomenator << endl;
    }

    void simplify()
    {
        int gcd = 1;
        int j = min(this->numerator, this->denomenator);
        for (int i = 1; i <= j; i++)
        {
            if (this->numerator % i == 0 && this->denomenator % i == 0)
            {
                gcd = i;
            }
        }
        this->numerator = this->numerator / gcd;
        this->denomenator = denomenator / gcd;
    }

    Fraction add(Fraction const &f2) const
    {
        int lcm = this->denomenator * f2.denomenator;
        int x = lcm / (this->denomenator);
        int y = lcm / f2.denomenator;
        int num = x * numerator + (y * f2.numerator);

        //numerator = num;
        //denomenator = lcm;
        Fraction fnew(num, lcm);

        fnew.simplify();
        return fnew;
    }

    Fraction operator+(Fraction const &f2) const
    {
        int lcm = this->denomenator * f2.denomenator;
        int x = lcm / (this->denomenator);
        int y = lcm / f2.denomenator;
        int num = x * numerator + (y * f2.numerator);

        //numerator = num;
        //denomenator = lcm;
        Fraction fnew(num, lcm);

        fnew.simplify();
        return fnew;
    }

    void multiply(Fraction const &f2)
    {

        numerator = numerator * f2.numerator;
        denomenator = denomenator * f2.denomenator;

        simplify();
    }

    Fraction operator*(Fraction const &f2) const
    {
        int n = numerator * f2.numerator;
        int d = denomenator * f2.denomenator;
        Fraction fnew(n, d);
        fnew.simplify();
        return fnew;
    }

    bool operator==(Fraction const &f2) const
    {
        return (numerator == f2.numerator && denomenator == f2.denomenator);
    }
    // pre increment
    Fraction &operator++()
    {
        numerator = numerator + denomenator;
        simplify();
        return *this;
    }

    // post increment
    Fraction operator++(int)
    {
        Fraction fnew(numerator, denomenator);
        numerator = numerator + denomenator;
        simplify();
        fnew.simplify();
        return fnew;
    }

    Fraction &operator+=(Fraction const &f2)
    {
        int lcm = this->denomenator * f2.denomenator;
        int x = lcm / (this->denomenator);
        int y = lcm / f2.denomenator;
        int num = x * numerator + (y * f2.numerator);

        numerator = num;
        denomenator = lcm;
        simplify();

        return *this;
        //Fraction fnew(num, lcm);
    }
};