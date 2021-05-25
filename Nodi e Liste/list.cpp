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
	
	Nodo<T>* _search(T key)
	{
		Nodo<T>* tmp = head;
		while(tmp && tmp->getKey() != key)
		{
			tmp = tmp->getNext();
		}
		return tmp;
	}
	
	

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
		while(tmp!=NULL && tmp->getKey() < key ){//ordinamento crescente -> se volessimo un ordinamento decrescente semplicemente scambio il < con >=
			p = tmp;
			tmp = tmp->getNext();
		}
		x->setNext(tmp);
		if(p) p->setNext(x);
		if(!p) head = x;
		n++;
		return *this;
	} 
	
	
	// inserimento in testa	
	Lista<T>& insert(T key)
	{          		         
 		Nodo<T> *y = new Nodo<T> (key);         	   
 		y->setNext(head);         
 		head = y;          
	 	n++;// aumento il numero di elementi dopo un inserimento         
	 	return *this;           
	} 
	
	
	int search(T key)
	{
		return (_search(key)!=NULL);
	}
	
	
	Lista<T>& canc(T key)
	{
		Nodo<T>* x = _search(key);
		if(!x) return *this;
		Nodo<T> *p = NULL;
		Nodo<T> *tmp = head;
		while(tmp!=NULL && tmp->getKey() < key)//stessa cosa se ala posto di tmp->getKey() < key mettessi tmp != x poichè alla fine del ciclo tmp DEVE essere uguale ad x
		{
			p = tmp;
			tmp = tmp->getNext();
		}
		if(p) p->setNext(tmp->getNext());
		else head = x->getNext();
		tmp->setNext(NULL);
		n--;
		delete x;
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

/*template <class T> std::ostream& operator<<(std::ostream& os, const Lista<T>& l)
{
	Lista<T> tmp = l;
	tmp.reset();
	os << "{ ";
	while(tmp.hasNext()){
		os << tmp.next() << " ";
	}
	os <<" }";
	return os;	

}*/


//se non voglio usare l' iteratore

template <class T> std::ostream& operator<<(std::ostream& os, const Lista<T>& l)
{
	Nodo<T>* tmp = l.getHead();
	
	while(tmp)
	{
		os << *tmp << "\n";
		tmp = tmp->getNext();
	}
	
	return os;

}
