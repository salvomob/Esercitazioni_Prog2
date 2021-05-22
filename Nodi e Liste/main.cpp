#include "list.cpp"
#include <iostream>

using namespace std;

int main()
{
	Lista<int> *l = new Lista<int>();
	
	l->ins(5).ins(4).ins(3).ins(6);
	
	cout << *l << endl;
}
