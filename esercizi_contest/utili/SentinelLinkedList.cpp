#include<iostream>
#include<cstdlib>

/*

Usiamo due nodi di servizio in testa ed in coda. Essi prendono il nome di Header e Trailer. Questi nodi sono ausiliari, non contengono alcuna key. Essi esistono anche a lista vuota. Alla creazione Header punta a Trailer. L'inserimento così sarà semplificato, perchè inseriremo sempre fra due nodi e duqnue non ci saranno dei casi in cui troviamo degli inserimenti in coda o in testa

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
    Nodo() {
        this->key = NULL;
        next = prev = NULL;
    }
    void setKey(T key) {*(this->key) = key;}
    void setNext(Nodo<T>* next) {this->next = next;}
    void setPrev(Nodo<T>* prev) {this->prev = prev;}
    T getKey() { return *key;}
    Nodo<T>* getNext() { return next;}
    Nodo<T>* getPrev() { return prev;}
};


template <class T> class SentinelLinkedList {
private:
	int n;
	Nodo<T> *Header,*Trailer,*current;
	Nodo<T>* _search(T key){
		Nodo<T> *tmp = Header->getNext();
		while(tmp!=Trailer && tmp->getKey()< key) tmp = tmp->getNext();
		if(tmp==Trailer) return NULL;
		if(tmp->getKey() == key) return tmp;
		return NULL;
	}	
public:
	SentinelLinkedList(){
	n=0;
	Header= new Nodo<T>();
	Trailer = new Nodo<T>();
	Header->setNext(Trailer);
	Trailer->setPrev(Header);
	current = NULL;
	}
	
	SentinelLinkedList<T>& ins(T key){
		Nodo<T> *tmp = Header->getNext();
		while(tmp!=Trailer && tmp->getKey() < key) tmp = tmp->getNext();
		Nodo<T> *x = new Nodo<T>(key);
		n++;
		//devo inserire la chiave prima di tmp
		x->setNext(tmp);
		x->setPrev(tmp->getPrev());		
	 	tmp->getPrev()->setNext(x);
		tmp->setPrev(x);				
		return *this;
	}
	SentinelLinkedList<T>& canc(T key){
		Nodo<T> *x =_search(key);
		if(x!=NULL){
			Nodo<T> *y = x->getPrev();
			Nodo<T> *z = x->getNext();
			y->setNext(z);
			z->setPrev(y);
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
		current = Header->getNext();
	}
	
	int hasNext(){
		return (current!= Trailer); 
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

template <class T> ostream& operator<<(ostream& os, const SentinelLinkedList<T>& d){
	SentinelLinkedList<T> tmp = d;
	os<<"{ ";
	tmp.reset();
	while(tmp.hasNext()){
		os << *(tmp.next()) << " "; 
	}
	os<<"}";
	return os;
}

int main(){
	SentinelLinkedList<string> *d = new SentinelLinkedList<string>();
	d->ins("selene").ins("salvatore").ins("peppino").ins("maria");
	cout << *d << endl;
	d->canc("selene").canc("salvatore");
	cout << *d << endl;
}
