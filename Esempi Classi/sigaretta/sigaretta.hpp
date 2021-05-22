#ifndef SIGARETTA_HPP
#define SIGARETTA_HPP

class Sigaretta{
private:

	double nicotina;
	double catrame;
	double palladio;
	double tabacco;
	bool industriale;
	std::string marca;

public:

	Sigaretta(){}
	
	Sigaretta(double nicotina,double catrame,double palladio,double tabacco,bool industriale,std::string marca);
	
	~Sigaretta();
	
	//metodi set
	
	void setNicotina(double);
	
	void setCatrame(double);
	
	void setPalladio(double);
	
	void setTabacco(double);
	
	void setIndustriale(bool);
	
	void setMarca(std::string);
	
	//metodi get
	
	double getNicotina() const;
	
	double getCatrame() const;
	
	double getPalladio() const;
	
	double getTabacco() const;
	
	bool getIndustriale() const;
	
	std::string getMarca() const;
	
	friend std::ostream& operator<<(std::ostream& os, const Sigaretta& s) 
	{
		os << "Marca : " << s.marca << "\n";
		os << "Nicotina : " << s.nicotina << "\n";
		os << "Catrame : " << s.catrame << "\n";
		os << "Palladio : " << s.palladio << "\n";
		os << "Tabacco : " << s.tabacco << "\n";		
		if(s.industriale) os << "Industriale!\n";
		else os << "Non Industriale!\n"; 
		return os;								
	}
};
#endif
