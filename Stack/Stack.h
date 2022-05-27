#pragma once

#include<iostream>
#include <Windows.h>
#include<string>
#include"MyData.h"

using namespace std;


struct numpunct
	: std::numpunct<char>
{
	std::string do_truename() const { return "The string is correct"; }
	std::string do_falsename() const { return "String is wrong"; }
};

template<class T, int size>
class DynamicStack
{
	MyData<T>* data = nullptr; 
	int top = 0;

public:
	~DynamicStack();
	void push(T val); 
	T pop(); 
	T peek(); 
	int getSize(); 
	bool isEmpty(); 
	bool isFull(); 
	void clear(); 
	void print() const;
};

template<class T, int size>
inline DynamicStack<T, size>::~DynamicStack()
{
	clear();
}

template<class T, int size>
inline void DynamicStack<T, size>::push(T val)
{
	if (top < size)
	{
		if (top == 0)
		{
			data = new MyData<T>;
			data->value = val;
		}

		else
		{
			MyData<T>* temp = new MyData<T>;
			temp->value = val;
			temp->next = data;
			data = temp;
		}
		top++;
	}

	else
	{
		cout << "stack full";
		system("pause");
		cout << endl;
	}
}

template<class T, int size>
inline T DynamicStack<T, size>::pop()
{
	T val = data->value;

	MyData<T>* temp = data;
	data = data->next;
	delete temp;
	top--;
	return val;
}

template<class T, int size>
inline T DynamicStack<T, size>::peek()
{
	if (top > 0)
		return data->value;
	else
	{
		cout << "The string you entered contains errors!\n";
		cout << "The number of closing brackets exceeds the number of opening ones.\n ";
		exit(1);
	}
}

template<class T, int size>
inline int DynamicStack<T, size>::getSize()
{
	return top;
}

template<class T, int size>
inline bool DynamicStack<T, size>::isEmpty()
{
	return top == 0;
}

template<class T, int size>
inline bool DynamicStack<T, size>::isFull()
{
	return top == size;
}

template<class T, int size>
inline void DynamicStack<T, size>::clear()
{
	MyData<T>* temp = data;
	while (data)
	{
		data = data->next;
		delete temp;
		temp = data;
		top--;
	}
}


template<class T, int size>
inline void DynamicStack<T, size>::print() const
{

	if (top == 0)
		cout << "Stack empty!";

	else
	{
		MyData<T>* temp = data;

		while (temp)
		{
			cout << temp->value;
			temp = temp->next;
		}
		cout << endl;
	}


}
