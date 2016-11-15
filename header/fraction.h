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

#pragma once
#include <iostream>

// Fraction contains a numerator and a denominator.
class Fraction {

public:
    // Member variables
    int numerator;
    int denominator;

    // Constructor for fraction. First number is the numberator. Second number is the denominator.
    Fraction(int num, int denom) : numerator(num), denominator(denom) {};


    // As it turns out, Operators are actually just functions that are defined in a special way.

    // These are operator declarartions for member functions:
    Fraction& operator+=(const Fraction second);    // Fraction& is the return type (usually += returns the object after it's modified)
    Fraction& operator-=(const Fraction second);    // operator+= is the "identifier", used when declaring an operator overload, where += could be any operator.
    Fraction& operator*=(const Fraction second);    // += is already a binary operator, which means it works on two objects, and this is a member function.
    Fraction& operator/=(const Fraction second);    // That means that object on the left of the operator (left operand) will be the object this function is called on,
                                                    // and the right operand will be the one passed into the parameters.
                                                    // It will secretly look like this: a.foo(b);
                                                    // We can make the right operand const because we won't modify it.
};


// Here, we declare operators for fractions outside of the class definition:
Fraction operator+(const Fraction first, const Fraction second);    // You'll notice that the initial part of this declaration is similar.
Fraction operator-(const Fraction first, const Fraction second);    // It doesn't return a reference because, the object will have just been created.
Fraction operator*(const Fraction first, const Fraction second);    // Since it isn't a member function, it needs to take in two parameters (left and right operand)
Fraction operator/(const Fraction first, const Fraction second);    // This will secretly look like this: foo(a, b);
                                                                    // They should both be const, because we won't change them to calculate the result.


// More operators, these compare fraction objects and return booleans:
bool operator==(const Fraction first, const Fraction second);
bool operator!=(const Fraction first, const Fraction second);
bool operator>(const Fraction first, const Fraction second);
bool operator<(const Fraction first, const Fraction second);
bool operator>=(const Fraction first, const Fraction second);
bool operator<=(const Fraction first, const Fraction second);


// Finally, a declaration for ostream, which helps us print out our fraction object.
// This is a little different than our other operators, this one takes an ostream on the left, and an object on the right.
// It then prints out the object on the right and returns the same ostream.
// This is what allows chaining of << when printing things.
std::ostream& operator<<(std::ostream& output, const Fraction& f);