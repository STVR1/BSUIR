#include"Operations.h"

void  Correspondence::Prototype1()
{
	bool nothing = true, check=false;
	std::vector<int> prototype;
	std::vector<int>buf;
	int element;

	std::cout << "Input the power of set" << std::endl;
	std::cin >> element;

	std::cout << "Create a new set" << std::endl;
	do
	{
		std::cin >> element;
		prototype.push_back(element);
	} while (std::cin.peek() != '\n');

	std::cout << "The result: ";
	for (int i = 0; i < G1.size(); i++)
	{
		for (int j = 0; j < prototype.size(); j++)
		{
			if (G1[i].second == prototype[j])
			{
				for (int k = 0; k < buf.size(); k++)
				{
					if (buf[k] == G1[i].first)
					{
						check = true;
						break;
					}
				}
				if (check == false)
				{
					if (nothing == true)nothing = false, std::cout << "{ ";
					std::cout << G1[i].first << " ";
					buf.push_back(G1[i].first);
				}
				else check = false;
			}
		}
	}
	if (nothing == false)std::cout << "}";
	else std::cout << "Empty set";
	std::cout << std::endl;

	prototype.erase(prototype.begin(), prototype.end());
	buf.erase(buf.begin(), buf.end());
}

void  Correspondence::Prototype2()
{
	bool nothing = true, check = false;
	std::vector<int> prototype;
	std::vector<int>buf;
	int element;

	std::cout << "Input the power of set" << std::endl;
	std::cin >> element;

	std::cout << "Create a new set" << std::endl;
	do {
		std::cin >> element;
		prototype.push_back(element);
	} while (std::cin.peek() != '\n');

	std::cout << "The result: ";
	for (int i = 0; i < G2.size(); i++)
	{
		for (int j = 0; j < prototype.size(); j++)
		{
			if (G2[i].second == prototype[j])
			{
				for (int k = 0; k < buf.size(); k++)
				{
					if (buf[k] == G2[i].first)
					{
						check = true;
						break;
					}
				}
				if (check == false)
				{
					if (nothing == true)nothing = false, std::cout << "{ ";
					std::cout << G2[i].first << " ";
					buf.push_back(G2[i].first);
				}
				else check = false;
			}
		}
	}
	if (nothing == false)std::cout << "}";
	else std::cout << "Empty set";
	std::cout << std::endl;

	prototype.erase(prototype.begin(), prototype.end());
	buf.erase(buf.begin(), buf.end());
}
