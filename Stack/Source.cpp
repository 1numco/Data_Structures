#include <iostream>
#include <vector>
#include "Header.h"
using namespace std;
Stack::Stack()
{

}

Stack::~Stack()
{

}

Stack::Stack(Stack*& st)
{
	mass = st->mass;
}

void Stack::Push(int n)
{
	mass.push_back(n);
}

void Stack::isEmpty()
{
	if (mass.empty() == true)
		cout << "Stack is empty" << endl;
	else
		cout << "Stack isn't empty" << endl;
}

int Stack::Pop()
{
	vector<int>::iterator it;
	it = mass.end()-1;
	int n = *it;
	mass.erase(it);
	return n;
}

int Stack::Top()
{
	vector<int>::iterator it;
	it = mass.end()-1;
	return *it;
}

void Stack::Show()
{
	vector<int>::iterator it;
	for (it = mass.end(); it > mass.begin(); it--)
		cout << *(it - 1) << " ";
	cout << endl;
}

void Stack::Delete()
{
	mass.erase(mass.begin(), mass.end());
	cout << "Stack was removed"<<endl;
}