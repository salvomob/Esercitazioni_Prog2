#include<iostream>
#include<fstream>
using namespace std;

class Persona{
protected:
	string nome;
	int eta;
	
public:
	Persona(){
		this->nome = "";
		this->eta = 0;
	}
	
	Persona(string _nome, int _eta){
		this->nome = _nome;
		this->eta = _eta;
	}
	
	void print(){
		cout << "Mi chiamo " << this->nome << " e ho "<< this->eta << " anni" << endl;
	}
	
	void parla(){
		cout << "Sono "<< this->nome << " e sto parlando da solo" << endl;
	}
	
	void parla(string s){
		cout << "Sono " << this->nome << " e sto parlando con " << s << endl;
	}	
};

class Oratore : public Persona{
public:

	Oratore() : Persona(){}
	
	Oratore(string _nome, int _eta) : Persona(_nome , _eta){}
	
	void parla(){
		cout << "Sono l'oratore " << nome <<  " e sto facendo un discorso" << endl;	
	}
	
	void parla(ostream& out){
		out << "Sono l'oratore " << nome <<  " e sto facendo un discorso" << endl;	
	}

};


int main(){
	ofstream os("output.txt");
	Persona p1;
	Persona p2("Salvatore",23);
	p1.print();
	p1.parla();
	p1.parla("Marco");
	p2.print();
	p2.parla();
	p2.parla("Marco");
	Oratore o1("Cicerone",2000);
	o1.parla();
	o1.parla(os);
}
