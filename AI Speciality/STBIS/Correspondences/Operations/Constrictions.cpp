#include"Operations.h"

void  Correspondence::Constriction1()
{
	bool nothing = true;
	std::vector<int> constriction;
	int element;

	std::cout << "Input the power of set" << std::endl;
	std::cin >> element;

	std::cout << "Create a new set" << std::endl;
	do{
		std::cin >> element;
		constriction.push_back(element);
	} while (std::cin.peek() != '\n');

	std::cout << "The result: ";

	std::cout << "{ ";
	for (int i = 0; i < constriction.size(); i++)std::cout << constriction[i] << " ";
	std::cout << "} { ";
	for (int i = 0; i < Y1.size(); i++)std::cout << Y1[i]<<" ";
	std::cout << "} ";

	for (int i = 0; i < G1.size(); i++)
	{
		for (int j = 0; j < constriction.size(); j++)
		{
			if (G1[i].first == constriction[j])
			{
				if (nothing == true)nothing = false, std::cout << "{ ";
				std::cout<<"< " << G1[i].first << " "<<G1[i].second<<" > " ;
			}
		}
	}
	if (nothing == false)std::cout << "}";
	else std::cout << "Empty set";
	std::cout << std::endl;

	constriction.erase(constriction.begin(), constriction.end());
}

void  Correspondence::Constriction2()
{
	bool nothing = true;
	std::vector<int> constriction;
	int element;

	std::cout << "Input the power of set" << std::endl;
	std::cin >> element;

	std::cout << "Create a new set" << std::endl;
	do{
		std::cin >> element;
		constriction.push_back(element);
	} while (std::cin.peek() != '\n');

	std::cout << "The result: ";
	for (int i = 0; i < G1.size(); i++)
	{
		for (int j = 0; j < constriction.size(); j++)
		{
			if (G2[i].first == constriction[j])
			{
				if (nothing == true)nothing = false, std::cout << "{ ";
				std::cout << "< " << G2[i].first << " " << G2[i].second << " > ";
			}
		}
	}
	if (nothing == false)std::cout << "}";
	else std::cout << "Empty set";
	std::cout << std::endl;

	constriction.erase(constriction.begin(), constriction.end());
}
