/*

LISTA SEMPLICEMENTE LINKATA CON INSERIMENTO NON ORDINATO

NELL'INSERIMENTO CREO DINAMICAMENTE IL NODO E LO VADO AD INSERIRE AL PROPRIO POSTO

*/

#include"nodo.cpp"
#include<iostream>

template <class T> class Lista {

private:

	Nodo<T> *head, *tail,*current;
	int n;

public:

	Lista()
	{
		head = tail = NULL;
		current = NULL;
		n = 0;
	}
	
	
	Lista<T>& ins(T key)
	{
		Nodo<T> *p = NULL;
		Nodo<T>* x = new Nodo<T>(key);
		Nodo<T>* tmp = head;
		if(tmp == NULL){
			head = x;
			return *this;
		} 
		while(tmp){
			p = tmp;
			tmp = tmp->getNext();
		}
		if(tmp == tail){
			x->setNext(tail);
			tail = x;
			p->setNext(x);
		}
		else{
			x->setNext(tmp);
			p->setNext(x);
		}
		return *this;
	} 	

	//iteratore
	
	void reset(){
		current = head;
	}
	
	int hasNext(){
		return (current != NULL);
	}
	
	T next(){
		T k = current->getKey();
		current = current->getNext();
		return k;	
	}
	
	//se non voglio usare l'iteratore
	
	Nodo<T>* getHead() const {return head;}
	Nodo<T>* getTail() const {return tail;}
	
};

template <class T> std::ostream& operator<<(std::ostream& os, const Lista<T>& l)
{
	Lista<T> tmp = l;
	tmp.reset();
	os << "{ ";
	while(tmp.hasNext()){
		os << tmp.next() << " ";
	}
	os <<" }";
	return os;	

}


//se non voglio usare l' iteratore
/*
template <class T> std::ostream& operator<<(std::ostream& os, const Lista<T>& l)
{
	Nodo<T>* tmp = l.getHead();
	
	while(tmp)
	{
		os << *tmp << "\n";
		tmp = tmp->getNext();
	}
	
	return os;

}*/
