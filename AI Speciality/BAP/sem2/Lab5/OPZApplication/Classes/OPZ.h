#pragma once

#include<iostream>

class OPZ
{

private:

	int Prior(char c);

	char Out[255];

	double arr[255];

public:


	OPZ(char* In, double* arr);

	double Calculate();

	char* GetOPZ();

};