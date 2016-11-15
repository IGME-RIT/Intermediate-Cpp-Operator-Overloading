/*
Operator Overloading
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "../header/fraction.h"
#include <iostream>
using namespace std;

// Operators are special types of functions that allow us to write code witha convenient syntax.

// Start of main function
int main() 
{
    {
        // Create a fraction class to test the operator overloads it has
        Fraction a = Fraction(1, 2);
        Fraction b = Fraction(1, 3);

        // One of the most commonly used operator overloads for many objects, << allows use to easily print important object data.
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;

        // Test addition:
        cout << "a + b: " << (a + b) << endl;

        // Test subtraction:
        cout << "a - b: " << (a - b) << endl;

        // Test multiplication:
        cout << "a * b: " << (a * b) << endl;

        // Test division:
        cout << "a / b: " << (a / b) << endl;


        cin.get(); // Wait for input to continue.


        // Test addition assignment:
        cout << "a += b: " << (a += b) << endl;

        // Test subtraction assignment:
        cout << "a -= b: " << (a -= b) << endl;

        // Test multiplication assignment:
        cout << "a *= b: " << (a *= b) << endl;

        // Test division assignment:
        cout << "a /= b: " << (a /= b) << endl;
    }
    cin.get();


    {
        // Test comparisons operators:

        // == and !=
        if (Fraction(1, 2) == Fraction(2, 4))
        {
            cout << "1/2 == 2/4" << endl;
        }


        if (Fraction(2, 3) != Fraction(4, 9))
        {
            cout << "2/3 != 4/9" << endl;
        }

        // > and <
        if (Fraction(2, 3) > Fraction(4, 9))
        {
            cout << "2/3 > 4/9" << endl;
        }

        if (Fraction(2, 3) < Fraction(4, 9))
        {
            cout << "2/3 < 4/9" << endl;
        }

        // >= and <=
        if (Fraction(2, 3) >= Fraction(4, 9))
        {
            cout << "2/3 >= 4/9" << endl;
        }

        if (Fraction(2, 3) <= Fraction(4, 9))
        {
            cout << "2/3 <= 4/9" << endl;
        }
    }
    cin.get();

    return 0;   // End Program.
}