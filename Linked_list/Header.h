#pragma once
#include <stdlib.h>
struct Node
{
	int data;
	Node* next;
};

class List 
{
private:
	Node *Head, *Tail;
public:
	List() : Head(NULL), Tail(NULL) {};
	~List();
	List(List*&);
	void Show();
	void InsertAtTail(int);
	void InsertAtHead(int);
	void Delete(int);
	void DeleteAtHead();
	void DeleteAtTail();
	Node* Search(int);
	void isEmpty();
};
