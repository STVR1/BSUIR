#include"Operations.h"

void  Correspondence::Continuation1()
{

	std::cout << "Result: < { ";
	for (int i = 0; i < X1.size(); i++)std::cout << X1[i]<<" ";
	std::cout << "} { ";
	for (int i = 0; i < Y1.size(); i++)std::cout << Y1[i] << " ";
	std::cout << "} { ";
	for (int i = 0; i < UniverseG.size(); i++)std::cout << "< " << UniverseG[i].first << " " << UniverseG[i].second << " > ";
	std::cout << "} >";
	
}

void  Correspondence::Continuation2()
{
	std::vector<int> continuation;
	int element, counter = 0;
	std::cout << "Create a new set" << std::endl;

	do{
		std::cin >> element;
		continuation.push_back(element);
	} while (std:: cin.peek() != '\n');

	for (int i = 0; i < continuation.size(); i++)
	{
		for (int j = 0; j < G2.size(); j++)
		{
			if (continuation[i] == G2[j].first)
			{
				counter++;
				break;
			}
		}
	}

	std::cout << "The result: ";
	if (counter == continuation.size())
	{
		std::cout << "{ ";
		for (int i = 0; i < G2.size(); i++)
		{
			std::cout << "< " << G2[i].first << " " << G2[i].second << " > ";
		}
		std::cout << "}";
	}
	else std::cout << "Empty set";

	std::cout << std::endl;

	continuation.erase(continuation.begin(), continuation.end());
}