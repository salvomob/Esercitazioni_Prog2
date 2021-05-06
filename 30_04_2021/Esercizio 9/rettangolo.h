#ifndef RETTANGOLO_H
#define RETTANGOLO_H

class Rettangolo{
private:
	int lato1;
	int lato2;
	
public:
	Rettangolo(int l1,int l2){//l1 e l2 sono dei valori che setterò all'interno del main mentre lato1 e lato2 sono delle variabili di classe
	//l1 e l2, una volta finito il codice del costruttore non esistono più mentre lato1 o meglio this->lato1 e.... esisteranno sempre
		this->lato1 = l1;
		this->lato2 = l2;
	}
	
	
	int perimetro(){
		return (this->lato1+this->lato2)*2; // così va bene :)
		
	}
	
	int area(){
		return (this->lato1*this->lato2);
	}

};//N.B. alla fine della definizione di una classe va sempre il ; !!!!!!!
#endif


