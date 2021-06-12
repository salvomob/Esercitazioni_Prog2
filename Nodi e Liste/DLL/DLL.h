#ifndef DLL_H
#define DLL_H

#include"nodo.h"
#include<iostream>

template <class T> class DLL{
private:
	int n;//size della lista
	Nodo<T> *head,*tail,*current;
	
	Nodo<T>* _search(Nodo<T>* x)
	{
		Nodo<T>* tmp = head;
		while(tmp)
		{
			if(tmp->getKey() == x->getKey()) return tmp;
			tmp = tmp->getNext();
		}
		return NULL;
	}
	
	Nodo<T>* _search(T key)
	{
		Nodo<T>* tmp = head;
		while(tmp)
		{
			if(tmp->getKey() == key) return tmp;
			tmp = tmp->getNext();
		}
		return NULL;
	}	
	
	
public:
	DLL()
	{
		n = 0;
		head = tail = NULL;
		current = NULL;
	}
	
	void ins(Nodo<T>* x)
	{	
		Nodo<T>* tmp = head;
		while(tmp && tmp->getKey() < x->getKey())
		{
			tmp = tmp->getNext();
		}
		n++;
		x->setNext(tmp);
		if(head==NULL){//lista vuota
			x->setPrev(NULL);
			head = tail = x;
			return;
		}
		if(tmp!=NULL){
			// Head ->       <-[tmp]
			//        <-[x]->
			x->setPrev(tmp->getPrev());
			if(head==tmp) head = x;	//inserimento in testa	
			else tmp->getPrev()->setNext(x);
			tmp->setPrev(x);
		}
		else{//tmp == NULL -> inserimento in coda
			tail->setNext(x);
			x->setPrev(tail);
			tail=x;
		}
		return;
	}
	
	void ins(T key)
	{
		Nodo<T>* x = new Nodo<T>(key);
		Nodo<T>* tmp = head;
		while(tmp && tmp->getKey() < key)
		{
			tmp = tmp->getNext();
		}
		n++;
		x->setNext(tmp);
		if(head==NULL){//lista vuota
			x->setPrev(NULL);
			head = tail = x;
			return;
		}
		if(tmp!=NULL){
			// Head ->       <-[tmp]
			//        <-[x]->
			x->setPrev(tmp->getPrev());
			if(head==tmp) head = x;	//inserimento in testa	
			else tmp->getPrev()->setNext(x);
			tmp->setPrev(x);
		}
		else{//tmp == NULL -> inserimento in coda
			tail->setNext(x);
			x->setPrev(tail);
			tail=x;
		}
		return;
	}
	
	void canc(Nodo<T>* x)
	{
		x = _search(x);//mi identifica il nodo all'interno della lista
		if(x!=NULL){
			Nodo<T> *y = x->getPrev();
			Nodo<T> *z = x->getNext();
			if(y!=NULL) y->setNext(z);//se y esiste
			else head = z;//se y non esiste e quindi cancello la testa e modifico la nuova testa di conseguenza
			if(z) z->setPrev(y);
			else tail = y;
			n--;
			delete x;
		}	
		return;
	
	}
	
	void canc(T key)
	{
		Nodo<T> *x = _search(key);
		if(x!=NULL){
			Nodo<T> *y = x->getPrev();
			Nodo<T> *z = x->getNext();
			if(y!=NULL) y->setNext(z);//se y esiste
			else head = z;//se y non esiste e quindi cancello la testa e modifico la nuova testa di conseguenza
			if(z) z->setPrev(y);
			else tail = y;
			n--;
			delete x;
		}	
		return;
	}
	
	bool search(Nodo<T> *x)
	{
		return (_search(x)!=NULL);
	}
	
	
	bool search(T key)
	{
		return (_search(key)!=NULL);
	}
	
	int size()
	{
		return n;
	}
	
	bool isEmpty()
	{
		return (n==0);
	}
	
	//iteratore
	
	void reset()
	{
		current = head;
	}
	
	bool hasNext()
	{
		return (current!=NULL);
	}
	
	Nodo<T> *next1()
	{
		if(hasNext())
		{
			Nodo<T>* tmp = current;
			current = current->getNext();
			return tmp;
		}
		else return NULL;
	}
	
	T* next2()
	{
		if(hasNext())
		{
			T* tmp = new T(current->getKey());
			current = current->getNext();
			return tmp;
		}
		else return NULL;
	}
	

};

template <class T> std::ostream& operator<<(std::ostream& out, const DLL<T>& dll)
{
	DLL<T> tmp = dll;
	tmp.reset();
	out << "{ ";
	while(tmp.hasNext())
	{
		out << *(tmp.next2()) << " ";
	}
	out << "}";
	return out;
}



#endif
