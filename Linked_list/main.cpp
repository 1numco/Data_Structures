#include "Header.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int max = 20;

int main()
{
	List* lst = new List;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
		lst->InsertAtTail(rand() % max);
	for (int i = 0; i < 10; i++)
		lst->InsertAtHead(i);
	lst->Show();
	lst->Delete(rand() % max);
	lst->Show();
	lst->DeleteAtHead();
	lst->Show();
	lst->DeleteAtTail();
	lst->Show();
	delete lst;
	system("pause");
	return 0;
}