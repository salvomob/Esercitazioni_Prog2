#include<iostream>
#include<fstream>
using namespace std;

class Monomio{
private:
	int grado,coeff;
	Monomio *next,*prev;
public:

	Monomio(int coeff,int grado){
		this->grado = grado;
		this->coeff = coeff;
		this->next = NULL;
		this->prev = NULL;
	}

	// metodi set
	
	void setGrado(int grado){
		this->grado = grado;
	}
	
	void setCoeff(int coeff){
		this->coeff = coeff;
	}
	
	void setN(Monomio *next){
		this->next = next;
	}
	
	void setP(Monomio *prev){
		this->prev = prev;
	}
	
	// metodi get
	
	int getG(){
		return grado;
	}
	
	int getC(){
		return coeff;
	}
	
	Monomio *getN(){
		return next;
	}
	
	Monomio *getP(){
		return prev;
	}
	
};

ostream& operator<<(ostream& os,const Monomio& m){
	Monomio tmp = m;
//	os<<"(";
	if(tmp.getG()==0) os << tmp.getC();
	if(tmp.getG()==1) os << tmp.getC() << "x";
	if(tmp.getC()==1) os << "x^" << tmp.getG();
	else if(tmp.getG()!=0 && tmp.getC()!=0 && tmp.getG()!=1)os<< tmp.getC() << "x^" << tmp.getG();
//	os<<")";
	return os;
}


/*int main(){
	Monomio *m1 = new Monomio(2,3);
	Monomio *m2 = new Monomio(3,13);
	Monomio *m3 = new Monomio(5,5);
	Monomio *m4 = new Monomio(8,3);
	Monomio *m5 = new Monomio(9,35);
	Monomio *m6 = new Monomio(10,34);
	Monomio *m7 = new Monomio(23,33);
	cout << *m1 << endl;
	cout << *m2 << endl;
	cout << *m3 << endl;
	cout << *m4 << endl;
	cout << *m5 << endl;
	cout << *m6 << endl;
	cout << *m7 << endl;
	
}*/
