#include"Operations.h"

void Correspondence::Complement12()
{
	bool nothing = true;
	std::cout << "The result: < ";
	for (int i = 0; i < UniverseX.size(); i++)
	{
		for (int j = 0; j < X1.size(); j++)
		{
			if (UniverseX[i] == X1[j])break;
			if (j == X1.size() - 1)
			{
				if (nothing == true)nothing = false, std::cout << "{ ";
				std::cout << UniverseX[i]<<" ";
			}
		}
	}
	
	if (nothing == false)std::cout << "} ";
	else std::cout << "Empty Set ";
	nothing = true;
	for (int i = 0; i < UniverseY.size(); i++)
	{
		for (int j = 0; j < Y1.size(); j++)
		{
			if (UniverseY[i] == Y1[j])break;
			if (j == Y1.size() - 1)
			{
				if (nothing == true)nothing = false, std::cout << "{ ";
				std::cout << UniverseY[i] << " ";
			}
		}
	}

	if (nothing == false)std::cout << "} ";
	else std::cout << "Empty Set ";
	nothing = true;

	for (int i = 0; i < UniverseG.size(); i++)
	{
		for (int j = 0; j < G1.size(); j++)
		{
			if (UniverseG[i] == G1[j])break;
			if (j == G1.size() - 1)
			{
				if (nothing == true)nothing = false, std::cout << "{ ";
				std::cout << "< " << UniverseG[i].first << " " << UniverseG[i].second << " > ";
			}
		}
	}
	if (nothing == false)std::cout << "} ";
	else std::cout << "Empty Set ";
	std::cout << ">";
	std::cout << std::endl;
}

void Correspondence::Complement21()
{
	bool nothing = true;
	std::cout << "The result: < ";
	for (int i = 0; i < UniverseX.size(); i++)
	{
		for (int j = 0; j < X2.size(); j++)
		{
			if (UniverseX[i] == X2[j])break;
			if (j == X2.size() - 1)
			{
				if (nothing == true)nothing = false, std::cout << "{ ";
				std::cout << UniverseX[i] << " ";
			}
		}
	}

	if (nothing == false)std::cout << "} ";
	else std::cout << "Empty Set ";
	nothing = true;
	for (int i = 0; i < UniverseY.size(); i++)
	{
		for (int j = 0; j < Y2.size(); j++)
		{
			if (UniverseY[i] == Y2[j])break;
			if (j == Y2.size() - 1)
			{
				if (nothing == true)nothing = false, std::cout << "{ ";
				std::cout << UniverseY[i] << " ";
			}
		}
	}

	if (nothing == false)std::cout << "} ";
	else std::cout << "Empty Set ";
	nothing = true;

	for (int i = 0; i < UniverseG.size(); i++)
	{
		for (int j = 0; j < G2.size(); j++)
		{
			if (UniverseG[i] == G2[j])break;
			if (j == G2.size() - 1)
			{
				if (nothing == true)nothing = false, std::cout << "{ ";
				std::cout << "< " << UniverseG[i].first << " " << UniverseG[i].second << " > ";
			}
		}
	}
	if (nothing == false)std::cout << "} ";
	else std::cout << "Empty Set ";
	std::cout << ">";
	std::cout << std::endl;
}
