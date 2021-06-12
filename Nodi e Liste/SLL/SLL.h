#ifndef SLL_H
#define SLL_H

#include"nodo.h"
#include<iostream>

template <class T> class SLL{
private:
	int n;//size della lista
	Nodo<T> *header,*trailer,*current;
	
	Nodo<T>* _search(Nodo<T>* x)
	{
		Nodo<T>* tmp = header->getNext();
		while(tmp != trailer)
		{
			if(tmp->getKey() == x->getKey()) return tmp;
			tmp = tmp->getNext();
		}
		return NULL;
	}
	
	Nodo<T>* _search(T key)
	{
		Nodo<T>* tmp = header->getNext();
		while(tmp != trailer)
		{
			if(tmp->getKey() == key) return tmp;
			tmp = tmp->getNext();
		}
		return NULL;
	}	
	
	
public:
	SLL()
	{
		n = 0;
		header = new Nodo<T>();
		trailer = new Nodo<T>();
		header->setNext(trailer);
		trailer->setPrev(header);
		current = NULL;
	}
	
	void ins(Nodo<T>* x)
	{	
		Nodo<T> *tmp = header->getNext();
		while(tmp!=trailer && tmp->getKey() <x->getKey()) tmp = tmp->getNext();
		n++;
		x->setNext(tmp);
		x->setPrev(tmp->getPrev());		
	 	tmp->getPrev()->setNext(x);
		tmp->setPrev(x);
		return;
	}
	
	void ins(T key)
	{
		Nodo<T> *tmp = header->getNext();
		while(tmp!=trailer && tmp->getKey() < key) tmp = tmp->getNext();
		Nodo<T> *x = new Nodo<T>(key);
		n++;
		x->setNext(tmp);
		x->setPrev(tmp->getPrev());		
	 	tmp->getPrev()->setNext(x);
		tmp->setPrev(x);
		return;
	}
	
	void canc(Nodo<T>* x)
	{
		x = _search(x);//mi identifica il nodo all'interno della lista
		Nodo<T> *y = x->getPrev();
		Nodo<T> *z = x->getNext();
		y->setNext(z);//se y esiste
		z->setPrev(y);
		n--;
		delete x;	
		return;
	
	}
	
	void canc(T key)
	{
		Nodo<T> *x = _search(x);//mi identifica il nodo all'interno della lista
		Nodo<T> *y = x->getPrev();
		Nodo<T> *z = x->getNext();
		y->setNext(z);//se y esiste
		z->setPrev(y);
		n--;
		delete x;
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
		current = header->getNext();
	}
	
	bool hasNext()
	{
		return (current!=trailer);
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

template <class T> std::ostream& operator<<(std::ostream& out, const SLL<T>& sll)
{
	SLL<T> tmp = sll;
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
