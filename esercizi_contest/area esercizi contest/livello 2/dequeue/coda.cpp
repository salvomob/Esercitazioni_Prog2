#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;
/*

la classe Queue, implementata utilizzando i template per il riutilizzo del codice per diversi formati dati, è una struttura di tipo first in first out FIFO --> il primo elemento ad essere inserito in coda sarà anche il primo a poter essere estratto :     <--key <--[ <-- key <-- ]  key <--
*/

template <class H> class Queue{
private:
	int n,len,current, iterazioni;
	int head,tail;
	H** q;	
public:
	Queue(){
		n = 0;
		len = 100;//valore di default
		q = new H*[len];
		head = 0;
		tail = 0;
		iterazioni = 0;		
	}
	Queue(int len){
		n = 0;
		this->len=len;
		q = new H*[len];
		head = 0;
		tail = 0;
		iterazioni = 0;	
	}
	Queue<H>& enqueue(H key){
		if(n<len){
			q[tail] = new H(key);
			tail++;
			if(tail == len) tail = 0;
			n++; 
		}
		return *this;
	}
	H* dequeue(){
		if(n>0){
			H* tmp = q[head];
			head++;
			if(head == len) head = 0;
			n--;
			return tmp;
		}
		return NULL;
	} 
	int isEmpty(){
		return (n==0);	
	}

	//iteratore
	void reset(){
		current = head;
		iterazioni = 0;
	}
	int hasNext(){
		return (iterazioni < n);
	}
	H* next(){
		if(hasNext()){
			H* tmp = q[current];
			current++;
			if(current == len) current = 0;
			iterazioni++;
			return tmp;
		}
		return NULL;
	}

};


	template <class H> ostream& operator<< ( ostream& os , const Queue<H>&q){
		Queue<H> tmp = q;
		tmp.reset();
		while(tmp.hasNext()){
			
			os << *tmp.next() ; 		
		}
		return os;
	}

