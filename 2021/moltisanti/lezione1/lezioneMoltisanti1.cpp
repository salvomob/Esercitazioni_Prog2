/*

gerarchia di due classi : classe mammifero e classe gatto

*/

#include<iostream>

using namespace std;

class Mammifero{
	protected:
	
	string nomeSpecie;
	int numeroArti;
	int eta;
	string nome;
	
public:
	Mammifero(string _nomeSpecie,int _numeroArti, int _eta){
		nomeSpecie = _nomeSpecie;
		numeroArti = _numeroArti;
		eta = _eta; 
	}
	
	void print(){
		cout << "Mammifero di specie :" << nomeSpecie << ", ha " << numeroArti << " arti e ha " << eta << " anni" << endl;
	}
	
	void setNome(string nome){
		this->nome = nome;
	}	
};


class Gatto : public Mammifero{
	public:
	Gatto(int _eta): Mammifero("gatto",4,_eta){
			
	}
	
	void miagola(){
		cout << "MIAO" << endl;
	}
	
	void print(){
		cout << "Il nome del gatto e' " << nome << endl;
	}
};

class Cane : public Mammifero{
	private:
	string coloreCollare;
	public:
	Cane(int _eta,string _coloreCollare) : Mammifero("cane",4,_eta){
		coloreCollare = _coloreCollare;
	}
	
	
	
	void siedi(){
		cout << "il cane si e' seduto" << endl;
	}
	
	void abbaia(){
		cout << "BAU" << endl;
	}
	
	void printCane(){
		cout << "il cane ha il collare di colore " << coloreCollare <<endl;
	}
};

int main(){
	Mammifero m("gatto",4,10);
	m.print();
	Gatto g(5);
	g.setNome("marco");
	g.print();
	g.miagola();
	Cane c(4,"rosso");
	c.abbaia();
	c.siedi();
	c.printCane();
	
}
