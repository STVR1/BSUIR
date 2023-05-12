#include"HashTable.h"

// Private

unsigned long HashTable::HashFunc(std::string key) {
	unsigned long i = 0;
	for (int j = 0; key[j]; j++) i += key[j];
	return i % size;
}

void HashTable::HandleCollision(int index, std::string key, std::string value)
{
	
	Pair<std::string, std::string> pair;

	pair.first = key, pair.second = value;

	items[index]->collisions.Push(pair);

}

// Public

HashTable::HashTable(int size) : size(size), count(0), items(new HashItem* [size]) {
	for (int i = 0; i < size; i++)items[i] = nullptr;
}

bool HashTable::Insert(std::string key, std::string value)
{
	int index = HashFunc(key);
	HashItem* item = new HashItem(key, value);

	HashItem* current = items[index];

	if (current == nullptr)
	{
		if (count == size)
		{
			return false;
		}

		items[index] = item;
		count++;

		return true;
	}
	else
	{

		if (current->key == key)
		{
			items[index]->value = value;
			return true;
		}
		else
		{
			HandleCollision(index, key, value);
			return true;
		}

	}

}

std::string HashTable::Search(std::string key)
{
	int index = HashFunc(key);
	HashItem* item = items[index];


	if (item != nullptr) {
		
		if (item->key == key) return item->value;
		else
		{
			for (int i = 0; i < items[index]->collisions.Size(); i++)
			{
				if (items[index]->collisions[i].first == key)return items[index]->collisions[i].second;
			}
		}
	}
	return "";
}

bool HashTable::DeleteField(std::string key)
{
	int index = HashFunc(key);

	if (items[index] == nullptr)return false;

	if (items[index]->key != key)
	{
		for (int i = 0; i < items[index]->collisions.Size(); i++)
			if (items[index]->collisions[i].first == key)
			{
				(*items[index]).collisions[i].first = (*items[index]).collisions[0].first;
				(*items[index]).collisions[i].second = (*items[index]).collisions[0].second;
				items[index]->collisions.Pop();
				return true;
			}

		return false;
	}

	delete items[index], items[index] = nullptr;
	count--;

	return true;
}

void HashTable::Clear()
{
	if (items == nullptr) return;
	for (int i = 0; i < size; i++)if (items[i] != nullptr)delete items[i], items[i] = nullptr;
	delete[] items, items = nullptr;
}

HashTable::~HashTable()
{
	if (items != nullptr)Clear();
}