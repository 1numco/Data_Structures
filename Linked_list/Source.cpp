#include <iostream>
#include "Header.h"
using namespace std;

List::List(List*& lst)
{
	Head = lst->Head;
	Tail = lst->Tail;
}

List::~List()
{
	Node* temp = Head;
	while (temp!=NULL)
	{
		temp = Head->next;
		delete Head;
		Head = temp;
	}
	cout << "List was removed" << endl;
}
void List::InsertAtTail(int n)
{
	Node *temp = new Node;                     
	temp->data = n;                               
	temp->next = NULL;                         

	if (Head != NULL)                          
	{
		Tail->next = temp;                     
		Tail = temp;
	}
	else Head = Tail = temp;
}

void List::InsertAtHead(int n)
{
	Node *temp = new Node;
	temp->data = n;
	temp->next = NULL;

	if (Head != NULL)
	{
		temp->next = Head;
		Head = temp;
	}
	else Head = Tail = temp;
}

Node* List::Search(int n)
{
	Node* temp = Head;
	bool f = false;
	while (temp != NULL)
	{
		if (temp->data == n)
		{
			f = true;
			return temp;
		}
		temp = temp->next;
	}
	if (f == false)
		return NULL;
}

void List::Delete(int n)
{
	Node* temp;
	temp = this->Search(n);
	if (temp == NULL)
		cout << "Node with data = " << n << " wasn't found" << endl;
	else
	{
		cout << "Node with data = "<<n<<" was removed" << endl;
		if (temp->next != NULL)
		{
			temp->data = temp->next->data;
			temp->next = temp->next->next;
		}
		else
		{
			this->DeleteAtTail();

		}
			
	}
}

void List::DeleteAtHead()
{
	if (Head != NULL)
	{
		Node* temp = Head;
		cout << "Node at head was removed" << endl;
		Head = Head->next;
		delete temp;
	}
	else
		this->isEmpty();
}

void List::DeleteAtTail()
{
	if (Head != NULL)
	{
		Node* temp = Head;
		Node* next = Head->next;
		while (next != Tail)
		{
			temp = next;
			next = next->next;

		}
		cout << "Node at tail was removed" << endl;
		Tail = temp;
		Tail->next = NULL;
		delete next;
	}
	else
		this->isEmpty();
}

void List::isEmpty()
{
	if (Head == NULL)
		cout << "List is empty" << endl;
	else
		cout << "List isn't empty" << endl;
}

void List::Show()
{
	Node* temp=Head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
