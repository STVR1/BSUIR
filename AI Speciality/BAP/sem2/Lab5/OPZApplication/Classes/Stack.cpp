#include"Stack.h"

void MyStack::push_back(char info)
{
	Node* field = new Node;
	field->info = info;
	if (Top == nullptr)Top = field;
	else
	{
		field->next = Top;
		Top = field;
	}
}

void MyStack::pop_back()
{
	Node* field = Top->next;
	delete Top;
	Top = field;
}
