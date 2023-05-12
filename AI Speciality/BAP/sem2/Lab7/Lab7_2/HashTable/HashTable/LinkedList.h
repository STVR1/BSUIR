#pragma once

template<typename type>
class LinkedList
{

private:

	class Node
	{
	public:

		type info;
		Node* next;

		Node(type info) : next(nullptr), info(info) {
		}

		~Node() {
		}

	};

	Node* begin, * end;

public:

	LinkedList() : begin(nullptr), end(nullptr) {
	}

	void Push(type info)
	{
		Node* field = new Node(info);

		if (begin == nullptr)begin = end = field;
		else
		{
			end->next = field;
			end = field;
		}

	}

	void Pop()
	{
		if (begin == nullptr)return;

		Node* field = begin->next;

		delete begin, begin = nullptr;

		begin = field;

	}

	int Size()
	{
		Node* field = begin;
		int counter = 0;

		while (field != nullptr)
		{
			field = field->next;
			counter++;
		}

		return counter;
	}

	type& operator[](const int index)
	{

		int counter = 0;

		Node* field = begin;

		while (field != nullptr)
		{

			if (counter == index)return field->info;

			field = field->next;
			counter++;

		}

	}

	void Clear()
	{
		while (begin != nullptr)Pop();
	}

	~LinkedList()
	{
		Clear();
	}

};