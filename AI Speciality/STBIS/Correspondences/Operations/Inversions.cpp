#include"Operations.h"

void Correspondence::Inversion1()
{
	std::cout << "The result: < { ";
	for (int i = 0; i < Y1.size(); i++)std::cout << Y1[i] << " ";
	std::cout << "} ";

	std::cout << "{ ";
	for (int i = 0; i < X1.size(); i++)std::cout << X1[i] << " ";
	std::cout << "} ";

	std::cout << "{ ";
	for (int i = 0; i < G1.size(); i++)std::cout << "< " << G1[i].second << " " << G1[i].first << " > ";
	std::cout << "} >";
	
	std::cout << std::endl;
}

void Correspondence::Inversion2()
{
	std::cout << "The result: < { ";
	for (int i = 0; i < Y2.size(); i++)std::cout << Y2[i] << " ";
	std::cout << "} ";

	std::cout << "{ ";
	for (int i = 0; i < X2.size(); i++)std::cout << X2[i] << " ";
	std::cout << "} ";

	std::cout << "{ ";
	for (int i = 0; i < G2.size(); i++)std::cout << "< " << G2[i].second << " " << G2[i].first << " > ";
	std::cout << "} >";
	
	std::cout << std::endl;
}
