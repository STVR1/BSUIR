#pragma once

#include<iostream>

class MyStack
{

private:

	struct Node
	{
		char info = 0;

		Node* next = nullptr;
	};

	Node* Top = nullptr;

public:

	void push_back(char info);

	void pop_back();

	Node* top()
	{
		return Top;
	}

};