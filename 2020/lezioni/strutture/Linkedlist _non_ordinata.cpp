#include<iostream>
using namespace std;


/*
head -->[4]-->[7]-->[9]-->[11]-->[15]-->[18]--> X

usiamo la memoria come un enorme array. Gli elementi della lista sono collegati tramite puntatori (in questo caso il next, poiche singolarmenter linkata)

usiamo una classe Nodo 
ogni elemento è una coppia di valori(x,y)

x = la chiave , ovvero il valore da memorizzare nella struttura
y = la posizione del succesivo elemento in memoria

*/
template <class T> class Nodo {
private:
	T* key;
	Nodo<T>* next;

public:
	Nodo(T key){
		this->key=new T(key);
		next = NULL;
	}
	void setKey(T key){*(this->key) = key;}
	void setNext(Nodo<T>* next){this->next=next;}
	T getKey(){return *key;}
	Nodo<T>* getNext(){return next;}
	
};


template <class T> class LinkedList {
private:
	int n;// numero elementi
	Nodo<T> *head, *current;
	Nodo<T>* _search(T key,Nodo<T> **p){
		Nodo<T> *x = head;
		*p = NULL;
		while(x!= NULL && x->getKey()!=key){
			*p = x;			
			x = x->getNext();
		}
		if(x && x->getKey()==key) return x;
		return NULL;
	}
public:
	LinkedList(){// costruisce una lista vuota
		n = 0;
		head = current = NULL;
	}
	
	LinkedList<T>& ins(T key){
		// inserimento in testa	
		Nodo<T> *y = new Nodo<T> (key);
		y->setNext(head);
		head = y;
		n++;// aumento il numero di elementi dopo un inserimento
		return *this;
	}

	LinkedList<T>&  canc(T key){
		Nodo<T> *p;
		Nodo<T> *x= _search(key, &p);
		if(x==NULL) return *this;
		Nodo<T> *y = x->getNext();
		if(p==NULL) head =y;
		else p->setNext(y);
		return *this;	
	}
	
	int search(T key){
		Nodo<T>* p;
		return (_search(key,&p)!=NULL);
	}
	
	int isEmpty(){return (n==0);}

	// iteratore
	
	void reset(){
		current = head;	
	}
	
	int hasNext(){
		return (current!=NULL);		
	}
	
	T* next(){
		if(!hasNext()) return NULL;
		T* tmp = new T(current->getKey());
		current = current->getNext();		
		return tmp;
	}		
};

ostream& operator<<(ostream& os, const LinkedList<int>& l){
	LinkedList<int> tmp = l;
	tmp.reset();
	os<<"{ ";
	while(tmp.hasNext()){
		os<< *(tmp.next()) << " ";
	}
	os<<"}";
	return os;

}

int main(){
	LinkedList<int> l ;
	l.ins(11).ins(7).ins(15).ins(4).ins(10);
	cout << l << endl;
	cout << l.search(7) << endl;
	cout << l.search(8) << endl;
	/*l.canc(7);
	l.canc(4);
	l.canc(15);
	cout << l << endl;
	return 0;*/
}
