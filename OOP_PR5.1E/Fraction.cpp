#pragma warning(disable : 4996)
#include "Fraction.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
using namespace std;

Fraction::Fraction()
    : integer(), fraction()
{}

Fraction::Fraction(int i, int f)
{
    if (f < 0)
    {
        throw invalid_argument("invalid_argument: The value less than 0!");
    }
    set_integer((long)i);
    set_fraction((unsigned short)f);
}

istream& operator >> (istream& in, Fraction& a)
{
    int f, s;
    cout << " Set the integer "; cin >> f;
    cout << " Set the fraction "; cin >> s;
    if (s < 0)
    {
        throw MyException("MyException: The value less than 0!");
    }
    a.set_integer((long)f);
    a.set_fraction((unsigned short)s);
    return in;
}

void Fraction::set_fraction(int f)
{
    if (f < 0)
    {
        throw Exception("Exception: The value less than 0!");
    }
    else
    {
        fraction = f;
    }
};

Fraction::Fraction(const Fraction& f)
{
    *this = f;
}

Fraction& Fraction::operator = (const Fraction& f) {
    integer = f.integer;
    fraction = f.fraction;
    return *this;
}

ostream& operator << (ostream& out, const Fraction& a)
{
    out << string(a);
    return out;
}

Fraction::operator string () const
{
    stringstream a;
    a <<  get_integer() << "." << get_fraction() << endl;
    return a.str();
}

void Read(Fraction& a)
{
    cout << "Set the number:" << endl; cin >> a;
}

void Display(Fraction& a)
{
    cout << a;
}

double toNumber(string str)
{
    double number;
    istringstream ( str ) >> number;
    return number;
}

double convertToDouble(Fraction& a)
{
    return toNumber(string(a));
}

Fraction toFraction(double n)
{
    stringstream s;
    s << n;

    string str = s.str();
    char* dup = strdup(str.data());

    string integer_a = strtok(dup, ".");
    string fraction_a = strtok(0, "");
    free(dup);
    Fraction nn;
    long int integer_b;
    istringstream(integer_a) >> integer_b;
    nn.set_integer(integer_b);

    unsigned short int fraction_b;
    istringstream(fraction_a) >> fraction_b;
    nn.set_fraction(fraction_b);

    return nn;
}

Fraction operator + (Fraction& a, Fraction& b)
{
    double sum =  convertToDouble(a) + convertToDouble(b);
    Fraction n = toFraction(sum);
    return n;
}

Fraction operator * (Fraction& a, Fraction& b)
{
    double sum =  convertToDouble(a) * convertToDouble(b);
    return toFraction(sum);
}
