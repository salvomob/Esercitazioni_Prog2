#include"studenti.h"
#include<iostream>


	inline Studente::Studente(std::string name,std::string surname, int age){
		nome = name;
		cognome = surname;
		eta = age;
	}
	
	inline std::string Studente::getNome(){
		return nome;
	}
	
	inline std::string Studente::getCognome(){
		return cognome;
	}
	
	inline int Studente::getEta(){
		return eta;
	}
	
	inline void Studente::show(){
		std::cout << "Ciao sono " << getNome() << " " << getCognome() << " ed ho " << getEta() << " anni\n";
	}
	
	inline void Studente::operator=(const Studente& s){
		this-> nome = s.nome;
		this->cognome = s.cognome;
		this->eta = s.eta;
	}


