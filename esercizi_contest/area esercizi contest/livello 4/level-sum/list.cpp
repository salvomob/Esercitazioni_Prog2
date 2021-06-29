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
template <class T> class Node {
private:
	T* key;
	Node<T>* next;

public:
	Node(T key){
		this->key=new T(key);
		next = NULL;
	}
	void setK(T key){*(this->key) = key;}
	void setN(Node<T>* next){this->next=next;}
	T getK(){return *key;}
	Node<T>* getN(){return next;}
	
};


template <class T> class List {
private:
	int n;// numero elementi
	Node<T> *head, *current;
	Node<T>* _search1(T key,Node<T> **p){
		Node<T> *x = head;
		*p = NULL;
		while(x!= NULL && x->getK()!=key){
			*p = x;			
			x = x->getN();
		}
		if(x && x->getK()==key) return x;
		return NULL;
	}
public:
	List(){// costruisce una lista vuota
		n = 0;
		head = current = NULL;
	}
	
	List<T>& insert(T key){
		// inserimento in testa	
		Node<T> *y = new Node<T> (key);
		y->setN(head);
		head = y;
		n++;// aumento il numero di elementi dopo un inserimento
		return *this;
	}

	List<T>&  canc(T key){
		Node<T> *p;
		Node<T> *x= _search1(key, &p);
		if(x==NULL) return *this;
		Node<T> *y = x->getN();
		if(p==NULL) head =y;
		else p->setN(y);
		return *this;	
	}
	
	int search1(T key){
		Node<T>* p;
		return (_search1(key,&p)!=NULL);
	}
	
	int isEmpty1(){return (n==0);}

	// iteratore
	
	void reset(){
		current = head;	
	}
	
	int hasNext(){
		return (current!=NULL);		
	}
	
	T* next(){
		if(!hasNext()) return NULL;
		T* tmp = new T(current->getK());
		current = current->getN();		
		return tmp;
	}
	
	void printList(){
		Node<T>* tmp = head;
		while(tmp){
			cout << tmp->getK()<< " ";
			tmp = tmp->getN(); 
		} 	
	}		
};

/*ostream& operator<<(ostream& os, const LinkedList<int>& l){
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
	return 0;
}*/
