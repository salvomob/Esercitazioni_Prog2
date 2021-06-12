#ifndef NODO_H
#define NODO_H

#include<iostream>


template <class T> class Nodo
{
private:
	T* key;
	Nodo<T> *prev, *next;
public:

	~Nodo(){}
	
	Nodo()
	{
		this->key = NULL;
		prev = NULL;
		next = NULL;
	}
	
	
	Nodo(T key)
	{
		this->key = new T(key);
		prev = next = NULL;
	}
	
	//metodi set
	
	void setKey(T key)
	{
		this->key = new T(key);
	}
	
	void setPrev(Nodo<T>* prev)
	{
		this->prev = prev;
	}
	
	void setNext(Nodo<T>* next)
	{
		this->next = next;
	}
	
	//metodi get
	
	T getKey() const
	{
		return *(this->key);
	}
	
	Nodo<T>* getNext() const
	{
		return next;
	}
	
	Nodo<T>* getPrev() const
	{
		return prev;
	}	
};

template <class T> std::ostream& operator<<(std::ostream& out, const Nodo<T>& n)
{
	out <<  n.getKey() << "\n" ;
	if(n.getNext()) out << "Next : " << *(n.getNext()) << "\n" ;
	else out << "NULL\n";
	if(n.getPrev()) out << "Prev: " << *(n.getPrev()) << "\n";
	else out <<"NULL\n";
	return out;
}


#endif
