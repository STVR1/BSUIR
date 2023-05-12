#include"OPZ.h"
#include"Stack.h"

int OPZ::Prior(char c)
{

	switch (c)
	{

	case '*': case '/':return 3;

	case '+':case '-':return 2;

	case '(':return 1;

	}

	return 0;
}

OPZ::OPZ(char* In, double* arr)
{
	MyStack op;
	int k = 0, i = 0;
	char a;
	while (In[k] != '\0')
	{
		if (In[k] >= 'a' && In[k] <= 'z')
		{
			Out[i++] = In[k];
		}
		if (In[k] == '(')op.push_back(In[k]);

		if (In[k] == ')')
		{
			while (op.top()->info != '(')
			{
				a = op.top()->info;
				op.pop_back();
				if (!op.top())
					a = '\0';
				Out[i++] = a;
			}
			op.pop_back();
		}
		if (In[k] == '+' || In[k] == '-' || In[k] == '*' || In[k] == '/')
		{
			while (op.top() != nullptr && Prior(op.top()->info) >= Prior(In[k]))
			{
				a = op.top()->info;
				op.pop_back();
				Out[i++] = a;
			}
			op.push_back(In[k]);
		}
		k++;
	}

	while (op.top() != nullptr)
	{
		a = op.top()->info;
		op.pop_back();
		Out[i++] = a;
	}
	Out[i] = '\0';

	while (op.top() != nullptr)op.pop_back();

	bool letters[26];
	for (i = 0; i < 26; i++)letters[i] = true;
	for (i = 0, k = 0; i < strlen(Out); i++)
	{
		if (Out[i] >= 'a' && Out[i] <= 'z') {
			if (letters[int(Out[i]) - 97] == true) {
				letters[int(Out[i]) - 97] = false;
				this->arr[int(Out[i])] = arr[k++];
			}
		}
	}

}

double OPZ::Calculate()
{
	char buff;
	double number1, number2;
	MyStack top;
	char middle = 'z' + 1;
	double result;
	for (int i = 0; i < strlen(Out); i++)
	{
		if (Out[i] >= 'a' && Out[i] <= 'z')top.push_back(Out[i]);
		else if (Out[i] == '*' || Out[i] == '+' || Out[i] == '/' || Out[i] == '-')
		{
			buff = top.top()->info;
			top.pop_back();
			number1 = arr[int(buff)];

			buff = top.top()->info;
			top.pop_back();
			number2 = arr[int(buff)];

			switch (Out[i])
			{
			case '+': result = number1 + number2; break;
			case '-': result = number2 - number1;   break;
			case '*': result = number1 * number2;  break;
			case '/': result = number2 / number1;   break;
			}

			arr[int(middle)] = result;
			top.push_back(middle);
			middle++;
		}
	}
	while (top.top() != nullptr)top.pop_back();

	return result;
}

char* OPZ::GetOPZ()
{
	return this->Out;
}