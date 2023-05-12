#pragma once

#include<iostream>

#include"LinkedList.h"
#include"PairClass.h"

class HashTable
{

private:

	class HashItem
	{

	public:

		LinkedList<Pair<std::string, std::string>> collisions;

		std::string key;
		std::string value;


		HashItem(std::string key, std::string value) : key(key), value(value), collisions(LinkedList<Pair<std::string, std::string>>()) {
		}

		~HashItem() {
		}

	};

private:

	HashItem** items;

	int size;
	int count;

	unsigned long HashFunc(std::string key);

	void HandleCollision(int index, std::string key, std::string value);

public:

	HashTable(int size);

	bool Insert(std::string key, std::string value);

	std::string Search(std::string key);

	bool DeleteField(std::string key);

	void Clear();

	~HashTable();

};