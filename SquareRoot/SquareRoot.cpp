// SquareRoot.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "SquareRoot.h"


// This is an example of an exported variable
SQUAREROOT_API int nSquareRoot=0;

// This is an example of an exported function.
SQUAREROOT_API int fnSquareRoot(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see SquareRoot.h for the class definition
CSquareRoot::CSquareRoot()
{
	return;
}

// Find the square root of a number.
double CSquareRoot::GetSquareRoot(double v)
{
    return 0.0;
}
