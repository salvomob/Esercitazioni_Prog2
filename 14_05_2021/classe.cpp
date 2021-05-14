#include"studenti.h"
#include"classe.h"
#include<iostream>
	
	inline Classe::Classe(int n){
		this->n = n;
		studenti = new Studente*[n];
		for(int i= 0; i < this->n; i++){
			studenti[i] = NULL;
		}
		this->myn = 0;
	}
	
	
	inline void Classe::setStudente(Studente& s){
		if(this->myn == this->n) return;
		this->myn = this->myn+1;
		studenti[this->myn-1] = &s;
	}
	
	
	void Classe::show(){
		std::cout << "Questa e' la classe : \n";
		for(int i = 0; i< this->myn; i++){
			studenti[i]->show();
		}
	}
