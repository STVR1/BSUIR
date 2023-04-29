#include"Operations.h"

void Correspondence::ShowCorrespodences()
{
	std::cout << "The first correspodence" << std::endl;
	std::cout << "< { ";
	for (int i = 0; i < X1.size(); i++)std::cout << X1[i]<<" ";
	std::cout << "} ";
	std::cout << "{ ";
	for (int i = 0; i < Y1.size(); i++)std::cout << Y1[i] << " ";
	std::cout << "} ";
	std::cout << "{ ";
	for (int i = 0; i < G1.size(); i++)std::cout <<"< " << G1[i].first << " " << G1[i].second << " > ";
	std::cout << "} > ";

	std::cout << std::endl;

	std::cout << "The second correspodence" << std::endl;
	std::cout << "< { ";
	for (int i = 0; i < X2.size(); i++)std::cout << X2[i] << " ";
	std::cout << "} ";
	std::cout << "{ ";
	for (int i = 0; i < Y2.size(); i++)std::cout << Y2[i] << " ";
	std::cout << "} ";
	std::cout << "{ ";
	for (int i = 0; i < G2.size(); i++)std::cout << "< " << G2[i].first << " " << G2[i].second << " > ";
	std::cout << "} > ";

	std::cout << std::endl;
	
}
