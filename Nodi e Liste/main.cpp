#include "list.cpp"
#include <iostream>

using namespace std;

int main()
{
	Lista<int> *l = new Lista<int>();
	
	l->ins(5).ins(4).ins(3).ins(6);
	
	cout << *l << endl;
	
	if(l->search(5)) cout << "il valore 5 risulta presente"<< endl;
	else cout << "Il valore 5 non risulta presente" << endl;
	
	if(l->search(23)) cout << "il valore 23 risulta presente"<< endl;
	else cout << "Il valore 23 non risulta presente" << endl;
	
	//cout << l->search(1) << endl;
	
	l->canc(6);
	
	cout << *l << endl;
	
}


