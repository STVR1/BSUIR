#include"HashTable.h"
#include<vector>
#include<fstream>
#include<string>
#include<regex>
#include<chrono>

bool Read(HashTable* table, std::string path)
{

	std::ifstream file(path);
	std::string line1, line2;
	if (file.is_open())
	{
		while (getline(file, line1))
		{
			getline(file, line2);
			table->Insert(line1, line2);
		}

		std::cout << "\nSuccessfully read\n";
		return true;
	}

	std::cout << "\nUnsuccessfully read\n";

	return false;
}

int ChoiceOperation()
{
	std::string line;
	std::regex check("^[1-3]{1}$");


	do
	{
		std::cout << "1. Search" << std::endl;
		std::cout << "2. Insert" << std::endl;
		std::cout << "3. Delete" << std::endl;
		getline(std::cin, line);
	} while (!regex_match(line, check));

	return stoi(line);
}

bool End()
{
	std::string line;
	std::regex check("^[1-2]$");

	do
	{
		std::cout << "Continue (1) or end (2)"<<std::endl;
		getline(std::cin, line);
	} while (!std::regex_match(line, check));

	if (stoi(line) == 1)return true;
	else return false;

}

std::string Key()
{
	std::string line;
	std::regex check("^([0-9]{2}[-]{1}){2}[0-9]{2}$");
	std::cout << "Input key" << std::endl;
	getline(std::cin, line);
	while (!std::regex_match(line, check))
	{
		std::cout << "Error. Repite" << std::endl;
		getline(std::cin, line);
	}
	return line;
}

int main()
{
	
	HashTable* table = new HashTable(15);
	std::string path="input.txt", key, value;

	if (!Read(table, path))return 0;

	do
	{

		switch (ChoiceOperation())
		{
		case 1:
		{
			key = Key();
			auto start = std::chrono::high_resolution_clock::now();
			value = table->Search(key);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float> duration = end - start;
			if (value == "")std::cout << "Nothing found" << std::endl;
			else std::cout << value<<"\t" << duration.count() << std::endl;
			break;
		}
		case 2:
		{
			key = Key();
			std::cout << "Input value" << std::endl;
			getline(std::cin, value);
			if (table->Insert(key, value))std::cout << "Successfully added" << std::endl;
			else std::cout << "Unsuccess" << std::endl;
			break;
		}
		case 3:
		{
			key = Key();
			if (table->DeleteField(key))std::cout << "Successfully deleted" << std::endl;
			else std::cout << "Nothing found" << std::endl;
			break;
		}
		}

	} while (End());
	

	
	return 0;
}