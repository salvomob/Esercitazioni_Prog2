#include<iostream>
#include<fstream>
#include "monomio.cpp"
#include<cstdlib>

using namespace std;




template <class T> class Polinomio {
private:
	int n;
	Monomio *Head,*Tail,*current;
	Monomio* _search(int coeff,int grado){
		Monomio *tmp = Head;
		while(tmp!=NULL && tmp->getG()> grado) tmp = tmp->getN();//scorro la lista per vedere se l'elemento che sto cercando è presente o meno
		if(tmp==NULL) return NULL;
		if(tmp->getG() == grado && tmp->getC() == coeff) return tmp;
		return NULL;
	}	
public:
	Polinomio(){
	n=0;
	Head = Tail = NULL;
	current = NULL;
	}
	
	Polinomio<T>& ins(int coeff,int grado){
		Monomio *tmp = Head;//scorriamo la lista grazie a questo nodo
		while(tmp!=NULL && tmp->getG()> grado) tmp = tmp->getN();
		Monomio *x = new Monomio(coeff,grado);
		n++;
		// [y] ->  <-[tmp]
		//    <- [x] ->	
		// devo inserire il monomio prima di tmp ->inserimento in mezzo alla lista
		x->setN(tmp);
		if(Head==NULL){//lista vuota
			x->setP(NULL);
			Head = Tail = x;
			return *this;	
		}
		if(tmp!=NULL){
			// Head ->      <-[tmp]
			//        <-[x]->
			x->setP(tmp->getP());
			if(Head==tmp) Head = x;	//inserimento in testa	
			else tmp->getP()->setN(x);
			tmp->setP(x);
		}
		else{//tmp == NULL -> inserimento in coda
			Tail->setN(x);
			x->setP(Tail);
			Tail=x;
		}				
		return *this;
	}
	Polinomio<T>& canc(int coeff,int grado){
		Monomio *x =_search(coeff,grado);
		if(x!=NULL){
			Monomio *y = x->getP();
			Monomio *z = x->getN();
			if(y) y->setN(z);
			else Head = z;
			if(z) z->setP(y);
			else Tail = y;
			n--;
		}	
		return *this;
	}
	int search(int coeff,int grado){
		return (_search(coeff,grado)!=NULL);
	}
	int isEmpty(){return (n==0);}
	int size(){return n;}
	// iteratore
	
	void reset(){
		current = Head;
	}
	
	int hasNext(){
		return (current!= NULL); 
	}
	
	Monomio* next(){
		if(hasNext()){
			Monomio *m = new Monomio(current->getC(),current->getG());
			current = current->getN();
			return m;
		}
		else return NULL;
			
	}
	
	Monomio* getH(){
		return Head;
	}
	
	Monomio* getT(){
		return Tail;
	}
	
	Monomio* getCR(){
		return current;
	}
	
	
	Polinomio<T>* addPoli(Polinomio<T>* p1, Polinomio<T>* p2){
		if(!p1 || !p2) return NULL;
		if(!p1) return p2;
		if(!p2) return p1;
		Polinomio<T> *ret = new Polinomio<T>();
		int *a = new int[p1->size()];
		int *b = new int[p1->size()];
		int *a1= new int[p2->size()];
		int *b1 = new int[p2->size()];
		Monomio *primo = p1->getH();
		Monomio *secondo = p2->getH(); 
		int i = 0;
		int j = 0;
		while(primo){
			a[i] = primo->getC();
			b[i] = primo->getG();
			i++;
			primo = primo->getN();
		}
		while(secondo){
			a1[j] = secondo->getC();
			b1[j] = secondo->getG();
			j++;
			secondo = secondo->getN();
		}
		
		for(int var1 = 0; var1 < p1->size(); var1++){
			for(int var2 = 0; var2 < p2->size(); var2++){
				if(b[var1] == b1[var2]) ret->ins((a[var1]+a1[var2]),b[var1]);
			}
		}
		return ret;
	}
	
	Polinomio<T>* sottPoli(Polinomio<T>* p1, Polinomio<T>* p2){
		if(!p1 || !p2) return NULL;
		if(!p1) return p2;
		if(!p2) return p1;
		Polinomio<T> *ret = new Polinomio<T>();
		int *a = new int[p1->size()];
		int *b = new int[p1->size()];
		int *a1= new int[p2->size()];
		int *b1 = new int[p2->size()];
		Monomio *primo = p1->getH();
		Monomio *secondo = p2->getH(); 
		int i = 0;
		int j = 0;
		while(primo){
			a[i] = primo->getC();
			b[i] = primo->getG();
			i++;
			primo = primo->getN();
		}
		while(secondo){
			a1[j] = secondo->getC();
			b1[j] = secondo->getG();
			j++;
			secondo = secondo->getN();
		}
		
		for(int var1 = 0; var1 < p1->size(); var1++){
			for(int var2 = 0; var2 < p2->size(); var2++){
				if(b[var1] == b1[var2]) ret->ins((a[var1]-a1[var2]),b[var1]);
			}
		}
		return ret;
	}	

};

ostream& operator<<(ostream& os, const Polinomio<int>& d){
	Polinomio<int> tmp = d;
	os<<"(";
	tmp.reset();
	int counter = 0;
	while(tmp.hasNext()){
		if(counter==tmp.size()-1) os << *(tmp.next());
		else{
			os << *(tmp.next()) << "+";
			counter++;
		} 
	}
	os<<")";
	return os;
}




int main(){
	Polinomio<int> *d = new Polinomio<int>();
	d->ins(1,2).ins(8,3).ins(9,2).ins(5,5).ins(5,1).ins(4,0);
	cout << *d << endl;
	Polinomio<int> *d1 = new Polinomio<int>();
	d1->ins(2,3).ins(5,0).ins(9,5);
	cout << *d1 << endl;
	cout << *d->sottPoli(d,d1) << endl;
}
