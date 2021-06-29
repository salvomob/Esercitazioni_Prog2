#include<iostream>
#include<cstdlib>

/*

Head 

*/

using namespace std;

template <class T> class Nodo {
private:
    T* key;
    Nodo<T> *next, *prev;
public:
    Nodo(T key) {
        this->key = new T(key);
        next = prev = NULL;
    }
    void setKey(T key) {*(this->key) = key;}
    void setNext(Nodo<T>* next) {this->next = next;}
    void setPrev(Nodo<T>* prev) {this->prev = prev;}
    T getKey() { return *key;}
    Nodo<T>* getNext() { return next;}
    Nodo<T>* getPrev() { return prev;}
};


template <class T> class DoubleLinkedList {
private:
	int n;
	Nodo<T> *Head,*Tail,*current;
	Nodo<T>* _search(T key){
		Nodo<T> *tmp = Head;
		while(tmp!=NULL && tmp->getKey()< key) tmp = tmp->getNext();//scorro la lista per vedere se l'elemento che sto cercando è presente o meno
		if(tmp==NULL) return NULL;
		if(tmp->getKey() == key) return tmp;
		return NULL;
	}	
public:
	DoubleLinkedList(){
	n=0;
	Head = Tail = NULL;
	current = NULL;
	}
	
	DoubleLinkedList<T>& ins(T key){
		Nodo<T> *tmp = Head;//scorriamo la lista grazie a questo nodo
		while(tmp!=NULL && tmp->getKey()< key) tmp = tmp->getNext();
		Nodo<T> *x = new Nodo<T>(key);
		n++;
		// [y] ->  <-[tmp]
		//    <- [x] ->	
		// devo inserire la key prima di tmp ->inserimento in mezzo alla lista
		x->setNext(tmp);
		if(Head==NULL){//lista vuota
			x->setPrev(NULL);
			Head = Tail = x;
			return *this;	
		}
		if(tmp!=NULL){
			// Head ->      <-[tmp]
			//        <-[x]->
			x->setPrev(tmp->getPrev());
			if(Head==tmp) Head = x;	//inserimento in testa	
			else tmp->getPrev()->setNext(x);
			tmp->setPrev(x);
		}
		else{//tmp == NULL -> inserimento in coda
			Tail->setNext(x);
			x->setPrev(Tail);
			Tail=x;
		}				
		return *this;
	}
	DoubleLinkedList<T>& canc(T key){
		Nodo<T> *x =_search(key);
		if(x!=NULL){
			Nodo<T> *y = x->getPrev();
			Nodo<T> *z = x->getNext();
			if(y) y->setNext(z);
			else Head = z;
			if(z) z->setPrev(y);
			else Tail = y;
			n--;
		}	
		return *this;
	}
	int search(T key){
		return (_search(key)!=NULL);
	}
	int isEmpty(){return (n==0);}

	// iteratore
	
	void reset(){
		current = Head;
	}
	
	int hasNext(){
		return (current!= NULL); 
	}
	
	T* next(){
		if(hasNext()){
			T *tmp = new T(current->getKey());
			current = current->getNext();
			return tmp;
		}
		else return NULL;
			
	}	

};

ostream& operator<<(ostream& os, const DoubleLinkedList<int>& d){
	DoubleLinkedList<int> tmp = d;
	os<<"{ ";
	tmp.reset();
	while(tmp.hasNext()){
		os << *(tmp.next()) << " "; 
	}
	os<<"}";
	return os;
}
/*
int main(){
	DoubleLinkedList<int> *d = new DoubleLinkedList<int>();
	d->ins(2).ins(1).ins(3).ins(9).ins(5);
	cout << *d << endl;
	d->canc(1).canc(9).canc(3);
	cout << *d << endl;
}*/
