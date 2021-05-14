/*
#ifndef LIST_H
#define LIST_H
*/
/*
Esercizio assegnato il 10 Maggio 2021 -->> linked list con parametro per l'ordinamento degli elementi
*/

#include<iostream>

using namespace std;//il demonio è qui!!

template <class T> class Nodo{
private:

	T* key;
	Nodo<T>* next;
	
public:

	Nodo(){
		this->key = NULL;
		this->next = NULL;
	}
	
	Nodo(T key){
		this->key=new T(key);
		next = NULL;
	}
	void setKey(T key){*(this->key) = key;}
	void setNext(Nodo<T>* next){this->next=next;}
	T getKey(){return *key;}
	Nodo<T>* getNext(){return next;}
	
};


template<class T> class List{
private:
	int n;//numero elementi nella lista
	Nodo<T> *head,*current;
	bool verso;//verso == true ordinamento crescente, bool == false ordinamento decrescente
	
	Nodo<T>* _search1(T key,Nodo<T> **p){//ricerca per verso == true
		Nodo<T> *x = head;
		*p = NULL;
		while(x!= NULL && x->getKey()<key){
			*p = x;			
			x = x->getNext();
		}
		if(x && x->getKey()==key) return x;
		return NULL;
	}
	
	Nodo<T>* _search2(T key,Nodo<T> **p){//ricerca per verso == false
		Nodo<T> *x = head;
		*p = NULL;
		while(x!= NULL && x->getKey()>key){
			*p = x;			
			x = x->getNext();
		}
		if(x && x->getKey()==key) return x;
		return NULL;
	}
	
public:
	
	List(bool v){
		this->verso = v;
		n = 0;
		head = current = NULL;
	}
	
	List<T>& ins(T key){
		Nodo<T> *x = head;
		Nodo<T> *p = NULL;
		if(this->verso){
			while(x!=NULL && x->getKey()<key){
				p = x;			
				x = x->getNext();
			}
		}
		else{
			while(x!=NULL && x->getKey()>key){
				p = x;			
				x = x->getNext();
			}
		}	
		Nodo<T> *y = new Nodo<T> (key);
		y->setNext(x);
		if(p) p->setNext(y);
		// inserimento in testa		
		else head = y;
		n++;// aumento il numero di elementi dopo un inserimento
		return *this;//restituisco l'intera lista, per poter fare inserimenti a cascata :)
	}
	
	
	List<T>&  canc(T key){
		Nodo<T> *p;
		Nodo<T>* x = new Nodo<T>();
		if(this->verso){
			x = _search1(key, &p);
		}
		else{
			x = _search2(key, &p);
		}
		if(x==NULL) return *this;
		Nodo<T> *y = x->getNext();
		if(p==NULL) head =y;
		else p->setNext(y);
		n--;
		return *this;//anche qui posso eseguire cancellazioni a cascata :)
	}
	
	
	int search1(T key){
		Nodo<T>* p;
		return (_search1(key,&p)!=NULL);
	}
	
	int search2(T key){
		Nodo<T>* p;
		return (_search2(key,&p)!=NULL);
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

template <class T> ostream& operator<<(ostream& os, const List<T>& l){
	List<int> tmp = l;
	tmp.reset();
	os<<"{ ";
	while(tmp.hasNext()){
		os<< *(tmp.next()) << " ";
	}
	os<<"}";
	return os;
	
}

//#endif
