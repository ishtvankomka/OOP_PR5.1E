#include <iostream>
#include <stddef.h>
#include <stdio.h>
#include "Fraction.hpp"
#include "Object.hpp"
using namespace std;

int main() {
    try
    {
        Fraction f1;
        cout << "First number: " << endl;
        cin >> f1;
        
        int integer2, fraction2;
        cout << "Second number: " << endl;
        cout << " Set the integer "; cin >> integer2;
        cout << " Set the fraction "; cin >> fraction2;
        Fraction f2(integer2, fraction2);
        
        Fraction nsum;
        nsum = f1 + f2;
        cout << "Sum: ";
        cout << nsum;
        
        Fraction nmultiplication;
        nmultiplication = f1 * f2;
        cout << "Multiplication: ";
        Display(nmultiplication);
        cout << "Object count: " << f1.get_count() << endl;
    }
    catch (MyException* e)
    {
        cerr << e->What() << endl;
    }
    catch (MyException& e)
    {
        cerr << e.What() << endl;
    }
    catch (invalid_argument e)
    {
        cerr << e.what() << endl;
    }
    
    try
    {
        Fraction f3;
        int integer3, fraction3;
        cout << "Third number: " << endl;
        cout << " Set the integer "; cin >> integer3;
        cout << " Set the fraction "; cin >> fraction3;
        f3.set_integer(integer3);
        f3.set_fraction(fraction3);
        cout << "Object count: " << f3.get_count() << endl;
    }
    catch (Exception* e)
    {
        cerr << e->What() << endl;
    }
    catch (Exception& e)
    {
        cerr << e.What() << endl;
    }

    return 0;
}
