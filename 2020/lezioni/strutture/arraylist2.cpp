/*
implementazione di una lista mediante l'uso di un array

una Lista è una struttura dati i cui elementi non sono necessariamente memorizzati in maneria contigua ll'interno della memoria(array in questo caso), ma ad ogni elemento è associato la posizione del successivo elemento
per una struttura è spesso costituita da una rappresentazione fisica erd una logica. ALla fine l'importante è mantenere la corretta rappr. logica.
RAPPRESENTAZIONE LOGICA(insieme ordinato):

S:[1]->[2]->[4]->[6]->[8]->[12]->[23]->[45]->X

RAPPRESENTAZIONE FISICA
   0  1  2 3 4 5 6 7  ..... (posizioni)
A:[23,45,1,2,6,8,4,12,_,_]
N:[1,X,3,6,5,7,4,0,_,_,_,](array delle posizioni: per ogni elemento ci dice qual'è il successivo nella rappresentazione logica)
Head:2->il numero 1(primo elemento della rappresentazione logica) si trova alla posizione 2 (della rappresentazione fisica "A")
*/
#include<iostream>
using namespace std;
#define X -1

/*     Appunti del Corso di Programmazione II (M-Z) - Docente Simone Faro
 Università degli Studi di Catania - Dipartimento di Matematica e Informatica
 Corso di Laurea Triennale in Informatica
 
 Implementazione di una Lista tramite utilizzo di un array
 */

/*
 
 
 rappresentazione logica (insieme ordinato):
 S:     [1]->[2]->[4]->[6]->[8]     [12]->[23]->[45]          X
    [0]->                     ->[9]->             --> [59] -->
         i                   p        i           p           i
 
 rappresentazione fisica
    0   1 2 3 4 5 6 7  8 9 10
 A:[23,45,1,2,6,8,4,12,_,_,_]
 N:[ 1, X,3,6,5,7,4, 0,_,_,_] N:next
 head:2
 
*/


#include <iostream>
using namespace std;
#define X -1

template <class T> class ArrayList {
private:
    T *A;
    int *N;
    int n, len, head, current;
    
    int _search(T x, int& p) { //restituisce la posizione in cui si trova x
        int i = head;
        p = X;
        while(i!=X && A[i]!=x) {
            p = i;
            i = N[i];
        }
        return i;
    }

    
public:
    ArrayList() {
        len = 10;
        n = 0;
        head = current = X;
        A = new T[len];
	for(int i=0;i<len;i++) A[i]=0;
        N = new int[len];
    }
    
    ArrayList& ins(T x) {// O(n)
	if(n==len) return *this;// altrimenti n < len --> meno elementi che posizioni, dunque posso effettuare l'inserimento
	//ricerca della prima posizione vuota
	int pos=0;
	while(A[pos]!=0) pos++;			//O(n)
        //inserimento nella rappresentazione fisica
        A[pos] = x;
        //inserimento nella rappresentazione logica
        int i = head;
        int p = X;
        while(i!=X && A[i]<x) {			//O(n)
            p = i;
            i = N[i];
        }
        //devo inserire x tra A[p] ed A[i]
        N[pos] = i; // x --> A[i]
        if(p!=X) N[p] = pos; // A[p] --> x
        else head = pos;
        n++;
        return *this;
    }

/*
S: [1]->[2]->[4]->[6]->[8]->[12]->[23]->[45]->X
                    -------->
                   p    i     t
A:[23,45,1,2,6,12,4,_,_,_,_]
N:[ 1, X,3,6,5,0 ,4,_,_,_,_]
 
*/
    void canc(T x) {
        int p;
        int i = _search(x,p);
        if(i==X) return;
        int t = N[i];
        if(p!=X) N[p] = t;
        else head = t;
	A[i]=0;
        n--;
    }
    
    int search(T x) {
        int p;
        return ( _search(x,p)!=X );
    }
    
    //iteratore
    void reset() {
        current = head;
    }
    
    int hasNext() {
        return (current!=X);
    }
    
    T* next() {
        if(!hasNext()) return NULL;
        T* tmp = &(A[current]);
        current = N[current];
        return tmp;
    }
    
    void print() {
        cout << "[ ";
        for(int i=0; i<len; i++) {
            cout << A[i] << " ";
        }
        cout << "]" << endl;
    }
};

ostream& operator<<(ostream& os, const ArrayList<int>& x) {
    ArrayList<int> y = x;
    y.reset();
    os << "{ ";
    while(y.hasNext()) {
        int *e = y.next();
        os << *e << " ";
    }
    os << "}";
    return os;
}


int main() {
    ArrayList<int> set;
    set.ins(12).ins(4).ins(3).ins(7).ins(26).ins(2);
    cout << set << endl;
    set.print();

    set.canc(7);
    cout << set << endl;
    set.print();

    set.canc(26);
    cout << set << endl;
    set.print();

    set.ins(8).ins(49);
    cout << set << endl;
    set.print();

}

