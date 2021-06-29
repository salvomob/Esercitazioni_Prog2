#include<iostream>
#include<fstream>

using namespace std;

class Animale{
private:
	int numeroArti;
	int numeroOcchi;
	bool coda;
	
	
	
protected:
	string nome;
	
	void descrivi(){
		cout << "L'animale in questione è bello\n";
	}
	
	void ciao(){
		cout << "CIAO\n";
	}
public:
	Animale(){}
	
	Animale(int numeroArti,int numeroOcchi, bool coda, string nome){
		this->numeroArti = numeroArti;
		this->numeroOcchi = numeroOcchi;
		this->coda = coda;
		this->nome = nome;
	}
	
	int sommaOA(){
		return (this->numeroArti+this->numeroOcchi);
	}
	
	void ciao1(){
		ciao();
		descrivi();
		cout << nome +"\n";
	}
};

class Lupo : public Animale{
private:
	int denti;
public:
	Lupo(int numeroArti,int numeroOcchi, bool coda,string nome,int denti) : Animale(numeroArti,numeroOcchi,coda,nome){
		this->denti  = denti;
	}
	
	int getDenti(){
		return denti;
	}
	
	void presentaLupo(){
		ciao1();
		cout << "l'animale in questione è un lupo\n";
		cout << "La somma di occhi e arti del lupo e' : " << sommaOA() <<"\n";
	}	
	
	void dentiLupo(){
		cout << "il lupo ha " << getDenti() << " denti\n";
	}
		
};

class Cane : public Lupo{
private:
	bool randagio;
	int id;
public:
	Cane(int numeroArti,int numeroOcchi, bool coda, string nome, int denti, bool randagio,int id) : Lupo(numeroArti,numeroOcchi,coda,nome,denti){
		this->randagio = randagio;
		this->id = id;
	}
	
	void dentiLupo(){
		cout << "il cane ha " << getDenti() << " denti\n";
	}
	
	void presentaLupo(){
		ciao1();
		cout << "l'animale in questione e' un cane\n";
		cout << "la somma di arti e occhi del cane e' " << sommaOA() << "\n";
		dentiLupo();
		if(randagio) cout << "il cane e' randagio\n";
		else cout << "il cane e' sicuramente di qualcuno, perche' questo e' il suo id :" << id << "\n"; 
	}
	
	
		
};


int main(){
	Animale a(4,2,true,"Francesco");
	a.ciao1();
	//a.descrivi();
	cout << a.sommaOA() << endl;
	Lupo l(3,1,false,"Lucio",42);
	l.presentaLupo();
	l.dentiLupo();
	Cane c(4,2,true,"Aiace",42,false,12345);
	c.presentaLupo();
	
}


