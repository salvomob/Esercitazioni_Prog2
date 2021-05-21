 #ifndef STUDENTE_H
 #define STUDENTE_H
 #include<string>
 
 class Studente{
 private:
 	std::string nome;
 	std::string cognome;
 	char sex;
 	int anno;
 	std::string locazione;
 	std::string matricola;
 	
 public:
 	Studente(std::string nome,std::string cognome,char sex,int anno,std::string locazione,std::string matricola);
 	
 	~Studente();
 	
 	//metodi set
 	
 	void setNome(std::string nome);
 	
 	void setCognome(std::string cognome);
 	
 	void setSex(char sex);
 	
 	void setAnno(int anno);
 	
 	void setLocazione(std::string locazione);
 	
 	void setMatricola(std::string matricola);
 	
 	//metodi get
 	
 	std::string getNome();
 	
 	std::string getCognome();
 	 	
 	char getSex();
 	 	 	
 	int getAnno();
 	 	 	 	
 	std::string getLocazione();
 	
 	std::string getMatricola();
 	
 	friend std::ostream& operator<<(std::ostream& os, const Studente& s) 
	{
		os << "Nome : " << s.nome << "\n";
		os << "Cognome : " << s.cognome << "\n";
		os << "Sesso : " << s.sex << "\n";
		os << "Anno : " << s.anno << "\n";
		os << "Locazione : " << s.locazione << "\n";		
		os << "Matricola : " << s.matricola << "\n";
		return os;								
	}

 	
 };
 
 
 #endif
