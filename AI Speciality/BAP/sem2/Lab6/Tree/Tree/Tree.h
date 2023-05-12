#pragma once

#include<iostream>
#include"Pair.h"

template<typename type1, typename type2>
class Node
{

private:

	Pair<type1, type2> pair;
	
public:

	Node<type1, type2>* left, * right;

	Node(Pair<type1, type2> pair) : pair(pair), left(nullptr), right(nullptr) {
	}
	
	Node() : left(nullptr), right (nullptr){
	}

	Pair<type1, type2>* GetPair()
	{
		return &this->pair;
	}

};

template<typename type1, typename type2>
class Tree
{

	typedef Node<type1, type2> TNode;

	typedef Pair<type1, type2> NPair;

private:

	TNode* root;

	Pair<type1, type2>* searched=nullptr;

	int tabs;

	void Add(TNode*& node, NPair pair)
	{
		if (!node)node = new Node<type1, type2>(pair);
		else
		{
			if (node->GetPair()->first > pair.first) Add(node->left, pair);
			else if(node->GetPair()->first<pair.first)Add(node->right, pair);
		}
	}

	void Delete(type1 key, TNode*& parent, TNode*& child)
	{
		if (!child)return;
		
		if (parent == child && child->GetPair()->first==key)
		{
			TNode* field1 = child->right;
			TNode* field2 = child;

			NPair min = (*field1->GetPair());

			while (true)
			{
				if (min.first > field1->GetPair()->first)min = (*field1->GetPair());
				if (field1->left == nullptr)break;
				field2 = field1;
				field1 = field1->left;
			}

			(*child->GetPair()) = min;

			if (field2 == child)
			{
				field2->right = field2->right->right;
				delete field1;
				field1 = nullptr;
			}
			else
			{
				field2->left = nullptr;
				delete field1;
				field1 = nullptr;
			}

			return;
		}
		
		if (child->GetPair()->first == key)
		{

			if (child->left == nullptr && child->right == nullptr)
			{
				
				if (parent->GetPair()->first > child->GetPair()->first)parent->left = nullptr;
				else parent->right = nullptr;
				
				delete child;         
				child = nullptr;
			}
			else if (child->left == nullptr)
			{
				if (parent->GetPair()->first > child->GetPair()->first)
				{
					auto field = child->right;
					delete child;
					child = nullptr;
					parent->left = field;
				}
				else
				{

					auto field = child->right;
					delete child;
					child = nullptr;
					parent->right = field;
				}

			}
			else if (child->right == nullptr)
			{

				if (parent->GetPair()->first > child->GetPair()->first)
				{
					auto field = child->left;
					delete child;
					child = nullptr;
					parent->left = field;
				}
				else
				{
					auto field = child->left;
					delete child;
					child = nullptr;
					parent->right = field;
				}

			}
			else
			{
				TNode* field1=child->right;
				TNode* field2 = child;

				NPair min=(*field1->GetPair());

				while (true)
				{
					if (min.first > field1->GetPair()->first)min = (*field1->GetPair());
					if (field1->left == nullptr)break;
					if (field1->left == nullptr)break;
					field2 = field1;
					field1 = field1->left;
				}

				(*child->GetPair())=min;

				if (field2 == child)field2->right = nullptr;
				else field2->left = nullptr;
				delete field1;
				field1 = nullptr;

				return;
			}

		}

		if(child)Delete(key,child, child->left);
		if(child)Delete(key,child, child->right);

	}

	void Clear(TNode*& node)
	{
		if (!node)return;
		Clear(node->left);
		Clear(node->right);
		delete node;
		node = nullptr;
		tabs = 0;
	}

	void Print(TNode* node)
	{
		if (!node)return;

		tabs += 5;

		Print(node->left);

		for (int i = 0; i < tabs; i++)std::cout << " ";
		std::cout << node->GetPair()->first<<std::endl;
		
		Print(node->right);

		tabs -= 5;
	}

	void Preorder(TNode* node)
	{
		if (!node)return;
		std::cout << node->GetPair()->first<<std::endl;
		Preorder(node->left);
		Preorder(node->right);
	}

	void Postorder(TNode* node)
	{
		if (!node)return;
		Postorder(node->left);
		Postorder(node->right);
		std::cout << node->GetPair()->first << std::endl;
	}

	void Inorder(TNode* node)
	{
		if (!node)return;
		Inorder(node->left);
		std::cout << node->GetPair()->first<<std::endl;
		Inorder(node->right);

	}

    void MakeBalanced(TNode** node, int n, int k, TNode* arr)
	{
		if (n == k)
		{
			*node = nullptr;
			return;
		}
		else
		{
			int middle = (n + k) / 2;
			*node= new Node<type1, type2>(arr[middle]);
			MakeBalanced(&(*node)->left, n, middle, arr);
			MakeBalanced(&(*node)->right, middle + 1, k, arr);
		}
	}

	NPair* Max(TNode* node)
	{
		if (node->right != nullptr) {
			return Max(node->right);
		}
		else {
			return node->GetPair();
		}
	}

	NPair* Min(TNode* node)
	{
		if (node->left != nullptr) {
			return Min(node->left);
		}
		else {
			return node->GetPair();
		}

	}

	void Find(type1 key, TNode* node)
	{
		if (!node)return;

		if (node->GetPair()->first == key)
		{
			searched = node->GetPair();
			return;
		}

		Find(key, node->left);

		Find(key, node->right);

	}

	int OneBranch(TNode* node, int& counter)
	{
		if (!node)return counter;
		if ((node->left == nullptr && node->right != nullptr) || (node->left != nullptr && node->right == nullptr)) counter++;
		OneBranch(node->left, counter);
		OneBranch(node->right, counter);
		return counter;
	}

	int Amount(TNode* node, int& size)
	{
		if (!node)return size;
		else size++;
		Amount(node->left, size);
		Amount(node->right, size);
		return size;
	}

	void QuickSort(TNode* arr, int start, int end)
	{
		if (start < end)
		{
			int left = start;
			int right = end;
			auto middle = arr[(start + end) / 2].GetPair()->first;
			do
			{
				while (arr[left].GetPair()->first < middle)left++;
				while (arr[right].GetPair()->first > middle)right--;
				if (left <= right)
				{
					Node<type1, type2> temp = arr[right];
					arr[right] = temp;
					left++;
					right--;
				}
			} while (left < right);
			QuickSort(arr, start, right);
			QuickSort(arr, left, end);
		}
	}

	void MakeArray(TNode* arr, TNode* node, int& index)
	{

		if (!node)return;

		MakeArray(arr, node->left, index);

		arr[index].GetPair()->first = node->GetPair()->first;
		arr[index++].GetPair()->second = node->GetPair()->second;

		MakeArray(arr, node->right, index);

	}


public:

	Tree() : root(nullptr), tabs(0) {
	}

	// Method to push node

	void Add(NPair pair)
	{
		Add(root, pair);
	}

	// Method to delete node

	void Delete(type1 key)
	{
		Delete(key, root, root);
	}

	// Method to print a tree like a tree 

	void Print()
	{
		Print(root);
	}

	// Method to print a tree (preorder traversal)

	void Preorder()
	{
		Preorder(root);
	}

	// Method to print a tree (inorder traversal)

	void Inorder()
	{
		Inorder(root);
	}

	// Method to print a tree (postorder traversal)

	void Postorder()
	{
		Postorder(root);
	}

	// Method to clear a tree

	void Clear()
	{
		Clear(root);
	}

	// Method to balance a tree

	void MakeBalanced()
	{
		int k=Amount(root, k=0), index=0;
		Node<type1, type2>* arr = new Node<type1, type2>[k];

		MakeArray(arr, root, index);
		QuickSort(arr, 0, k - 1);
		
		Clear(root);
		MakeBalanced(&root, 0, k, arr);
		delete[] arr;
	}

	// Method to create a tree using array with nodes

	void Emplace(NPair* array)
	{
		if (!array)return;
		for (int i = 0; i < _msize(array)/sizeof(Pair<type1, type2>); i++)Add(array[i]);
	}

	// Method to find a node using a key

	auto Find(type1 key)
	{
		searched = nullptr;
		Find(key, root);
		return searched;
	}

	// Method to check, if a tree is empty

	bool IsEmpty()
	{
		if (!root)return true;
		return false;
	}

	// Method to get a node with max key

	NPair* Max()
	{
		if (!root)return nullptr;
		return Max(root);
	}

	// Method to get a node with min key

	NPair* Min()
	{
		if (!root)return nullptr;
		return Min(root);
	}

	// Destructor with function Clear()

	int OneBranch()
	{
		int counter=0;
		return OneBranch(root, counter);
	}

	~Tree()
	{
		if (root != nullptr)Clear(root);
	}

};