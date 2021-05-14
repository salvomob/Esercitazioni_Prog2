#ifndef CLASSE_H
#define CLASSE_H
#include<iostream>

class Classe{
private:
	Studente **studenti;
	int n;//numero massimo studenti in classe
	int myn;//numero effettivo studenti in classe
public:
	Classe(int n);
	
	void setStudente(Studente& s);
	
	void show();
};

#endif
