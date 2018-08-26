#pragma once
using namespace std;
#include <vector>
class Stack
{
private:
	vector<int> mass;
public:
	Stack();
	~Stack();
	Stack(Stack*&);
	void Push(int);
	int Pop();
	void isEmpty();
	int Top();
	void Delete();
	void Show();
};
