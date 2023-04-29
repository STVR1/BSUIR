#include"Operations.h"

void Correspondence::Composition12()
{
	std::vector<std::pair<int, int>> composition;
	bool nothing = true, check=false;

	std::cout << "The result: < { ";
	for (int i = 0; i < X1.size(); i++) std::cout << X1[i]<<" ";
	std::cout << "} ";
	
	std::cout << "{ ";
	for (int i = 0; i < Y2.size(); i++)std::cout << Y2[i] << " ";
	std::cout << "} ";

	for (int i = 0; i < G1.size(); i++)
	{
		for (int j = 0; j < G2.size(); j++)
		{
			if (G1[i].second == G2[j].first)
			{
				for (int k = 0; k < composition.size(); k++)
				{
					if (G1[i].first == composition[k].first && G2[j].second == composition[k].second)
					{
						check = true;
						break;
					}
				}
				if (check == false)
				{
					if (nothing == true)nothing = false, std::cout << "{ ";
					std::cout << "< " << G1[i].first << " " << G2[j].second << " > ";
					composition.push_back(std::make_pair(G1[i].first, G2[j].second));
				}
				else check = false;
			}
		}
	}
	if (nothing == false)std::cout << "} ";
	else std::cout << "Empty Set ";
	std::cout << ">";
	std::cout << std::endl;

	composition.erase(composition.begin(), composition.end());
}

void Correspondence::Composition21()
{
	std::vector<std::pair<int, int>> composition;
	bool nothing = true, check = false;

	std::cout << "The result: < { ";
	for (int i = 0; i < X2.size(); i++) std::cout << X2[i] << " ";
	std::cout << "} ";

	std::cout << "{ ";
	for (int i = 0; i < Y1.size(); i++)std::cout << Y1[i] << " ";
	std::cout << "} ";

	for (int i = 0; i < G2.size(); i++)
	{
		for (int j = 0; j < G1.size(); j++)
		{
			if (G2[i].second == G1[j].first)
			{
				for (int k = 0; k < composition.size(); k++)
				{
					if (G2[i].first == composition[k].first && G1[j].second == composition[k].second)
					{
						check = true;
						break;
					}
				}
				if (check == false)
				{
					if (nothing == true)nothing = false, std::cout << "{ ";
					std::cout << "< " << G2[i].first << " " << G1[j].second << " > ";
					composition.push_back(std::make_pair(G2[i].first, G1[j].second));
				}
				else check = false;
			}
		}
	}
	if (nothing == false)std::cout << "} ";
	else std::cout << "Empty Set ";
	std::cout << ">";
	std::cout << std::endl;

	composition.erase(composition.begin(), composition.end());
}
