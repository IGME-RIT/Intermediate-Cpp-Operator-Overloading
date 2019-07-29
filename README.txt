Documentation Author: Niko Procopi 2019

This tutorial was designed for Visual Studio 2017 / 2019
If the solution does not compile, retarget the solution
to a different version of the Windows SDK. If you do not
have any version of the Windows SDK, it can be installed
from the Visual Studio Installer Tool

Welcome to the Operator Overload Tutorial!
Prerequesites: None

Operator overloading allows you to override what happens
when you add, subtract, multiply, or divide two types of data.
For two integers, attempting to add them, will obviously return the
sum of their values:
int a = 5;
int b = 4;
int c = a + b;
Of course 'c' will be 9, but here's the problem:

struct Example
{
	int a;
	int b;
	int c;
}

Example one;
Example two;
Example three;

three = one + two;

What happens now?

With operator overloading, you can choose exactly what happens when
two "Example" objects are added together. 
