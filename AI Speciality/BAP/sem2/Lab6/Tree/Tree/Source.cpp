#include<iostream>
#include"Tree.h"
#include<fstream>
#include<string>

void Read(Tree<int, std::string>& tree)
{

	std::string path="", line = "";

	Pair<int, std::string> pair;

	std::cout << "Input the path"<<std::endl;
	std::getline(std::cin, path);

	try
	{
		std::ifstream file(path);
		while (std::getline(file, line))
		{
			while (line == "")std::getline(file, line);
			pair.first = stoi(line);
			std::getline(file, line);
			while (line == "")std::getline(file, line);
			pair.second = line;
			tree.Add(pair);
		}
		file.close();
		std::cout << "Successfully read" << std::endl;
	}
	catch (const std::exception)
	{
		std::cout << "Can't open file";
	}

}

// Variant 1: change information between max and min keys

void Task(Tree<int, std::string>& tree)
{

	auto min = tree.Min();
	auto max = tree.Max();	
	auto temp = *min;

	std::cout << "\n\nMin element: " << min->first << "\t" << min->second << std::endl<<std::endl;
	std::cout << "\n\nMax element: " << max->first << "\t" << max->second << std::endl<<std::endl;

	*min = *max;
	*max = temp;

}

int main()
{

	srand(time(NULL));

	Tree<int, std::string> tree;

	Read(tree);

	if (!tree.IsEmpty())
	{

		std::cout << "\n\nPrechanged tree\n\n";

		tree.Print();

		Task(tree);

		std::cout << "\n\nPostchanged tree\n\n";

		tree.Print();

	}
	else std::cout << "Your tree is empty" << std::endl;

	return 0;
}