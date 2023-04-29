#include"Operations.h"

Correspondence::Correspondence()
{
	int powerX, powerY, element;

	std::cout << "Enter the power of send of the first match" << std::endl;
	std::cin >> powerX;

	std::cout << "Enter the elements of send of the first match" << std::endl;
	do{
		std::cin >> element;
		X1.push_back(element);
	} while (std::cin.peek() != '\n');

	std::cout << "Enter the power of arrival of the first match" << std::endl;
	std::cin >> powerY;

	std::cout << "Enter the elements of arrival of the first match" << std::endl;
	do{
		std::cin >> element;
		Y1.push_back(element);
	} while (std::cin.peek() != '\n');

	std::cout << "Enter the pairs of the first graphic" << std::endl;

	do {
		std::cin >> powerX>>powerY;
		G1.push_back(std::make_pair(powerX, powerY));
	} while (std::cin.peek() != '\n');

	std::cout << "Enter the power of send of the second match" << std::endl;
	std::cin >> powerX;

	std::cout << "Enter the elements of send of the second match" << std::endl;
	do{
		std::cin >> element;
		X2.push_back(element);
	} while (std::cin.peek() != '\n');

	std::cout << "Enter the power of arrival of the second match" << std::endl;
	std::cin >> powerY;

	std::cout << "Enter the elements of arrival of the second match" << std::endl;
	do{
		std::cin >> element;
		Y2.push_back(element);
	} while (std::cin.peek() != '\n');

	std::cout << "Enter the pairs of the second graphic" << std::endl;

	do {
		std::cin >> powerX >> powerY;
		G2.push_back(std::make_pair(powerX, powerY));
	} while (std::cin.peek() != '\n');

	for (int i = 1; i < 51; i++)UniverseX.push_back(i), UniverseY.push_back(i);

	for (int i = 0; i < 50; i++)for (int j = 0; j < 50; j++)UniverseG.push_back(std::make_pair(UniverseX[i], UniverseY[j]));
	
}
