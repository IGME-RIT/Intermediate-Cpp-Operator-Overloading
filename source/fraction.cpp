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



// Here, we define the operator overloads
// The following are not member functions, so they don't require a scope resolution operator ::

// Addition
Fraction operator+(const Fraction first, const Fraction second)
{
    int newNum = first.numerator * second.denominator + second.numerator * first.denominator;
    int newDenom = first.denominator * second.denominator;
    return Fraction(newNum, newDenom);
}

// Subtraction
Fraction operator-(const Fraction first, const Fraction second)
{
    int newNum = first.numerator * second.denominator - second.numerator * first.denominator;
    int newDenom = first.denominator * second.denominator;
    return Fraction(newNum, newDenom);
}

// Multiplication
Fraction operator*(const Fraction first, const Fraction second)
{
    int newNum = first.numerator * second.numerator;
    int newDenom = first.denominator * second.denominator;
    return Fraction(newNum, newDenom);
}

// Division
Fraction operator/(const Fraction first, const Fraction second)
{
    int newNum = first.numerator * second.denominator;
    int newDenom = second.numerator * first.denominator;
    return Fraction(newNum, newDenom);
}


// These are member functions, so they still need a scope resolution operator.
Fraction& Fraction::operator+=(const Fraction second)
{
    // Reuse + to make things simpler.
    // We use the value of this and add it to the other object, then return the this object.
    *this = *this + second;
    return *this;
}

// Overloading the -= operator with -
Fraction& Fraction::operator-=(const Fraction second)
{
    *this = *this - second;
    return *this;
}

// Overloading the *= operator with *
Fraction& Fraction::operator*=(const Fraction second)
{
    *this = *this * second;
    return *this;
}

// Overloading the /= operator with /
Fraction& Fraction::operator/=(const Fraction second)
{
    *this = *this / second;
    return *this;
}






// Overloading the == operator to compare two fractions.
bool operator==(const Fraction first, const Fraction second)
{
    // Cross multiply and compare.
    return first.numerator * second.denominator == first.denominator * second.numerator;
}

// Overloading the != operator to compare two fractions.
bool operator!=(const Fraction first, const Fraction second)
{
    // The opposite of ==
    return !(first == second);
}

// Overloading the > operator to compare two fractions.
bool operator>(const Fraction first, const Fraction second)
{
    // Cross multiply and compare.
    return first.numerator * second.denominator > second.numerator * first.denominator;
}

// Overloading the < operator to compare two fractions.
bool operator<(const Fraction first, const Fraction second)
{
    // Reverse numbers and use >.
    return second > first;
}

// Overloading the >= operator to compare two fractions.
bool operator>=(const Fraction first, const Fraction second)
{
    // If not less than, must be greater or equal.
    return !(first < second);
}

// Overloading the <= operator to compare two fractions.
bool operator<=(const Fraction first, const Fraction second)
{
    // If not greater than, must be less than or equal.
    return !(first > second);
}


// Override ostream operator to output fraciton as a string.
// This is how << works for most types.
std::ostream& operator << (std::ostream& output, const Fraction& f)
{
    return output << f.numerator << "/" << f.denominator;
}