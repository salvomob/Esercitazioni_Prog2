#include<iostream>
#include<fstream>
#include"rettangolo.hpp"
#include"rettangolo.cpp"
#include<unistd.h>

using namespace std;

int main()
{
	ifstream in("gesu.txt");
	Rettangolo *r = new Rettangolo();
	Rettangolo *r2 = new Rettangolo();
	in>>*r;//così creiamo un rettangolo attraverso l'operatore >> overloadato
	in>>*r2;//per ogni linea del file di input possiamo prendere un rettangolo;
	cout << *r << endl;
	
	delete r;
	usleep(1000);
	cout << *r << endl;//se vedete bene, tutti i valori saranno cambiati, poichè il rettangolo è stato eliminato ed al suo posto viene costruito un rettangolo non allocato con valori presi di default!!
	
	Rettangolo *r1 = new Rettangolo(0,100,100,0);//così creiamo un rettangolo direttamente nel main creandolo dinamicamente con 4 valori. N.B. si possono fare altre migliorie!!
	
	cout << *r1 << endl;
	
	cout << *r2 << endl;
}
