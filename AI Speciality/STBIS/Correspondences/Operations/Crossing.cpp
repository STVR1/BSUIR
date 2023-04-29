#include"Operations.h"

void Correspondence::Crossing()
{

	bool nothing = true;
	std::cout << "The result: < ";
	for (int i = 0; i < X1.size(); i++)
	{

			for (int j = 0; j < X2.size(); j++)
			{
				if (X1[i] == X2[j])
				{
					if (nothing == true)std::cout << "{ ", nothing = false;
					std::cout << X1[i] << " ";
					break;
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
				if (Y1[i] == Y2[j])
				{
					if (nothing == true)std::cout << "{ ", nothing = false;
					std::cout << Y1[i] << " ";
					break;
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
				if (G1[i] == G2[j])
				{
					if (nothing == true)nothing = false, std::cout << "{ ";
					std::cout << "< " << G1[i].first << " " << G1[i].second << " > ";
					break;
				}
			}
		

	}
	if (nothing == false)std::cout << "} ";
	else std::cout << "Empty Set ";
	std::cout << ">";
	std::cout << std::endl;
	

}
