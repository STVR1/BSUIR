#include"HashTable.h"

// Private

unsigned long HashTable::HashFunc(std::string key) {
	unsigned long i = 0;
	for (int j = 0; key[j]; j++) i += key[j];
	return i % size;
}

bool HashTable::HandleCollision(int index, std::string key, std::string value)
{
	items[index]->collision = true;
	for (int i = index + 1; i < size; i++)
	{
		if (items[i] == nullptr)
		{
			if (count == size)
			{
				return false;
			}
			items[i] = new HashItem(key, value);
			count++;
			return true;
		}
	}

	for (int i = 0; i < index; i++)
	{
		if (items[i] == nullptr)
		{
			if (count == size)
			{
				return false;
			}
			items[i] = new HashItem(key, value);
			count++;
			return true;
		}
	}
	return false;
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
			if (HandleCollision(index, key, value))return true;
			return false;
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
			for (int i = index + 1; i < size; i++)if (items[i] != nullptr)if (items[i]->key == key)return items[i]->value;
			for (int i = 0; i < index; i++)if (items[i] != nullptr)if (items[i]->key == key)return items[i]->value;
		}
	}
	return "";
}

bool HashTable::DeleteField(std::string key)
{
	int index = HashFunc(key);

	if (items[index] == nullptr)return false;

	if (items[index]->collision && items[index]->key == key)
	{
		for (int i = index + 1; i < size; i++)
			if (items[i] != nullptr)
				if (HashFunc(items[i]->key) == index)
				{
					items[index]->value = items[i]->value;
					items[index]->key = items[i]->key;
					items[index]->collision = false;
					delete items[i], items[i] = nullptr;
					count--;
					return true;
				}

		for (int i = 0; i < index; i++)
			if (items[i] != nullptr)
				if (HashFunc(items[i]->key) == index)
				{
					items[index]->value = items[i]->value;
					items[index]->key = items[i]->key;
					items[index]->collision = false;
					delete items[i], items[i] = nullptr;
					count--;
					return true;
				}
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