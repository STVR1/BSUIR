#pragma once

#include<iostream>

class HashTable
{

private:

	class HashItem
	{

	public:

		bool collision;

		std::string key;
		std::string value;


		HashItem(std::string key, std::string value) : key(key), value(value), collision(false) {
		}

		~HashItem() {
		}

	};

private:

	HashItem** items;

	int size;
	int count;

	unsigned long HashFunc(std::string key);

	bool HandleCollision(int index, std::string key, std::string value);

public:

	HashTable(int size);

	bool Insert(std::string key, std::string value);

	std::string Search(std::string key);

	bool DeleteField(std::string key);

	void Clear();

	~HashTable();

};