#include"Operations.h"

void Correspondence::Unit()
{
	std::cout << "The result: < { ";
	for (int i = 0; i < X1.size() + X2.size(); i++)
	{
		if (i < X1.size())std::cout << X1[i] << " ";
		else
		{
			for (int j = 0; j < X1.size(); j++)
			{
				if (X2[i - X1.size()] == X1[j])break;
				if (j == X1.size() - 1)std::cout << X2[i-X1.size()] << " ";
			}
		}

	}
	std::cout << "} ";

	std::cout << "{ ";
	for (int i = 0; i < Y1.size() + Y2.size(); i++)
	{
		if (i < Y1.size())std::cout << Y1[i] << " ";
		else
		{
			for (int j = 0; j < Y1.size(); j++)
			{
				if (Y2[i - Y1.size()] == Y1[j])break;
				if (j == Y1.size() - 1)std::cout << Y2[i-Y1.size()] << " ";
			}
		}

	}
	std::cout << "} ";

	std::cout << "{ ";
	for (int i = 0; i < G1.size() + G2.size(); i++)
	{
		if (i < G1.size())std::cout << "< " << G1[i].first << " " << G1[i].second << " > ";
		else
		{
			for (int j = 0; j < G1.size(); j++)
			{
				if (G2[i - G1.size()] == G1[j])break;
				if (j == G1.size() - 1)std::cout << "< " << G2[i-G1.size()].first << " " << G2[i-G1.size()].second << " > ";
			}
		}

	}
	std::cout << "} >";
	std::cout << std::endl;

}
