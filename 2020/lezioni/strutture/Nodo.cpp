#include<iostream>
#include<cstdlib>

using namespace std;

template <class T> class Nodo{
	private:
		T *key;
		Nodo<T>* next;*prev;
	public:
		Nodo(T key){
			this->key=key;
			next=prev=NULL;		
		}
		void setKey(T key){*(this->key)=key;}
		void setNext(Nodo<T>* next){this->next=next;}
		void setPrev(Nodo<T>* prev){this->prev=prev;}
		T getKey(){retrun *key;}
		Nodo<T>* getNext(){return next;}
		Nodo<T>* getPrev(){return prev;}
};
