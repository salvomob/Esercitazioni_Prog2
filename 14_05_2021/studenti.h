#ifndef STUDENTE_H
#define STUDENTE_H
#include<iostream>

class Studente{
private:
	std::string nome;
	std::string cognome;
	int eta;
public:

	Studente(){};
	
	Studente(std::string name,std::string surname, int age);
	
	std::string getNome();
	
	std::string getCognome();
	
	int getEta();
	
	void show();
	
	void operator=(const Studente&);
};

#endif
