#include"Operations.h"

void Correspondence::Diff12()
{
	bool nothing = true;
	std::cout << "The result: < ";
	for (int i = 0; i < X1.size(); i++)
	{
		for (int j = 0; j < X2.size(); j++)
		{
			if (X1[i] == X2[j])break;
			if (j == X2.size() - 1)
			{
				if (nothing == true)std::cout << "{ ", nothing = false;
				std::cout << X1[i] << " ";
			}
		}
	}

	if (nothing == false)std::cout << "} ";
	else std::cout << "Empty Set ";
	nothing = true;

	for (int i = 0; i < Y1.size(); i++)
	{
		for (int j = 0; j < Y2.size(); j++)
		{
			if (Y1[i] == Y2[j])break;
			if (j == Y2.size() - 1)
			{
				if (nothing == true)std::cout << "{ ", nothing = false;
				std::cout << Y1[i] << " ";
			}
		}
	}

	if (nothing == false)std::cout << "} ";
	else std::cout << "Empty Set ";
	nothing = true;


	for (int i = 0; i < G1.size(); i++)
	{
		for (int j = 0; j < G2.size(); j++)
		{
			if (G1[i] == G2[j])break;
			if (j == G2.size() - 1)
			{
				if (nothing == true)std::cout << "{ ", nothing = false;
				std::cout << "< " << G1[i].first << " " << G1[i].second << " > ";
			}
		}
	}
	if (nothing == false)std::cout << "} ";
	else std::cout << "Empty Set ";
	std::cout << ">";
	std::cout << std::endl;

}

void Correspondence::Diff21()
{
	bool nothing = true;
	std::cout << "The result: < ";
	for (int i = 0; i < X2.size(); i++)
	{
		for (int j = 0; j < X1.size(); j++)
		{
			if (X2[i] == X1[j])break;
			if (j == X1.size() - 1)
			{
				if (nothing == true)std::cout << "{ ", nothing = false;
				std::cout << X2[i] << " ";
			}
		}
	}

	if (nothing == false)std::cout << "} ";
	else std::cout << "Empty Set ";
	nothing = true;

	for (int i = 0; i < Y2.size(); i++)
	{
		for (int j = 0; j < Y1.size(); j++)
		{
			if (Y2[i] == Y1[j])break;
			if (j == Y1.size() - 1)
			{
				if (nothing == true)std::cout << "{ ", nothing = false;
				std::cout << Y1[i] << " ";
			}
		}
	}

	if (nothing == false)std::cout << "} ";
	else std::cout << "Empty Set ";
	nothing = true;


	for (int i = 0; i < G2.size(); i++)
	{
		for (int j = 0; j < G1.size(); j++)
		{
			if (G2[i] == G1[j])break;
			if (j == G1.size() - 1)
			{
				if (nothing == true)std::cout << "{ ", nothing = false;
				std::cout << "< " << G2[i].first << " " << G2[i].second << " > ";
			}
		}
	}
	if (nothing == false)std::cout << "} ";
	else std::cout << "Empty Set ";
	std::cout << ">";
	std::cout << std::endl;
}
