#include "Header.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int max = 40;
int main()
{
	Stack* st = new Stack;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
		st->Push(rand() % max);
	st->Show();
	int n1=st->Pop();
	cout << n1 << endl;
	int n2=st->Top();
	cout << n2 << endl;
	st->Show();
	st->Delete();
	st->isEmpty();
	system("pause");
	delete st;
	return 0;
}