#include<iostream>
#include<cstdlib>

using namespace std;

/*template <class T> class Nonso{
private:
	T n;
	Nonso<T> *s,*d;
	
public:
	Nonso(){
		this->n = "";
		this->s = NULL;
		this->d = NULL;
	}
	
	T getN(){
		return n;
	}
	
	Nonso<T>* getS(){
		return s;
	}	
	
	Nonso<T>* getD(){
		return d;
	}
	
	void setD(Nonso<T>* d){
		this->d = d;
	}	
	
	void setS(Nonso<T>* s){
		this->s = s;
	}
	
	void setN(T n){
		this->n = n;
	}
};

int main(){
	Nonso<string> *nonso = new Nonso<string>();
	Nonso<string> *nonso1 = new Nonso<string>();
	nonso->setN("CIAO");
	nonso1->setN("SONIA");
	nonso->setD(nonso1);
	nonso1->setS(nonso);
	cout << nonso->getN() <<  " ";
	cout << nonso1->getN() << endl;
	return 0;
}

*/


/*

l'operatore "new" permette di allocare la memoria dinamicamente , specificando ogni qual volta la dimensione che vogliamo per i nostri array/oggetti

*/

/*

attraverso l'operatore "*" ci riferiamo ad un array oppure ad un puntatore.
attraverso l'operatore "&" ci riferiamo ad un alias nonchè alla locazione di memoria puntata da puntatore

*/

int main(){

	string s[] = {"SONIA" , "E'" , "UNA", "RAGAZZA" , "MERAVIGLIOSA"};
	cout << *s << " ";
	cout << *(s+1) << " ";
	cout << *(s+2) << " ";
	cout << *(s+3) << " ";
	cout << *(s+4) << endl;

}








