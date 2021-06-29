/* 	Appunti del Corso di Programmazione II (M-Z) - Docente Simone Faro
	Università degli Studi di Catania - Dipartimento di Matematica e Informatica
	Corso di Laurea Triennale in Informatica
*/

// Vettori 
// Esempio: Somma degli elementi di due Array

#include <iostream>
using namespace std;

// prototipo delle funzioni
void stampa(int[], int);
void inizializza(int A[], int n, int x);

int main() {
	int A[] = {2,3,4,6,2,1,4,3};
	int B[100] = {2,5,3,3};
	int C[7] = {0};

	// calcolo della lunghezza dei vettori
	int nA = sizeof(A)/sizeof(int);
	int nB = sizeof(B)/sizeof(int);
	int nC = sizeof(C)/sizeof(int);
	cout << "Dimensione di A :\t" << nA << endl;
	cout << "Dimensione di B :\t" << nB << endl;
	cout << "Dimensione di C :\t" << nC << endl;

	// mostra il contenuto del vettore
	cout << "A :\t"; stampa(A,8);
	cout << "B :\t"; stampa(B,4);
	cout << "C :\t"; stampa(C,7);
	
	// inizializza il vettore A
	inizializza( A, 8, 3); 
	cout << "A :\t"; stampa(A,8);

	return 0; // 0 indica un'esecuzione corretta	
}


void stampa(int A[], int n) {
	for(int i = 0; i < n; i++)
		cout << A[i] << "\t";
	cout << "\n";
}

// passaggio di un array per irferimento
void inizializza(int A[], int n, int x) { 
	for(int i=0; i<n; i++)
		A[i] = x;
}
