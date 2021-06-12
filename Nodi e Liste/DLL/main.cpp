#include "DLL.h"
#include<iostream>
using namespace std;

int main()
{
	DLL<int> *l = new DLL<int>();
	Nodo<int> *x1 = new Nodo<int>(5);
	Nodo<int> *x2 = new Nodo<int>(7);
	Nodo<int> *x3 = new Nodo<int>(2);
	
	//cout << *x1 << "\n" << *x2 << "\n" << *x3 << "\n";
	
	
	l->ins(x1);
	l->ins(x2);
	l->ins(x3);
	cout << *l << endl;
	
	
	Nodo<int> *x4 = new Nodo<int>(45);
	
	
	/*
	
		funziona
		
	DLL<string> *l2 = new DLL<string>();
	
	l2->ins("Giulia");
	l2->ins("Sonia");
	l2->ins("Salvo");
		
	cout << *l2 << endl;*/
	
	l->canc(x4);
	
	cout << *l << endl;

}


