#include"studente.hpp"

Studente::Studente(std::string nome,std::string cognome,char sex,int anno,std::string locazione,std::string matricola)
{
	this->nome = nome;
	this->cognome = cognome;
	this->sex = sex;
	this->anno = anno;
	this->locazione = locazione;
	this->matricola = matricola;
}

Studente::~Studente()
{
	delete [] &this->nome;
	delete [] &this->cognome;
	delete [] &this->sex;
	delete [] &this->anno;
	delete [] &this->locazione;
	delete [] &this->matricola;
}

	inline void Studente::setNome(std::string nome)
	{
		this->nome = nome;
	}
 	
 	inline void Studente::setCognome(std::string cognome)
 	{
 		this->cognome = cognome;
 	}
 	
 	inline void Studente::setSex(char sex)
 	{
 		this->sex = sex;
 	}
 	
 	inline void Studente::setAnno(int anno)
 	{
 		this->anno = anno;
 	}
 	
 	inline void Studente::setLocazione(std::string locazione)
 	{
 		this->locazione = locazione;
 	}
 	
 	inline void Studente::setMatricola(std::string matricola)
 	{
 		this->matricola = matricola;
 	}
 	
 	//metodi get
 	
 	inline std::string Studente::getNome()
 	{
 		return this->nome;
 	}
 	
 	inline std::string Studente::getCognome()
 	{
 		return this->cognome;
 	}
 	 	
 	inline char Studente::getSex()
 	{
 		return this->sex;
 	}
 	 	 	
 	inline int Studente::getAnno()
 	{
 		return this->anno;
 	}
 	 	 	 	
 	inline std::string Studente::getLocazione()
 	{
 		return this->locazione;
 	}
 	
 	inline std::string Studente::getMatricola()
 	{
 		return this->matricola;
 	}
 	
