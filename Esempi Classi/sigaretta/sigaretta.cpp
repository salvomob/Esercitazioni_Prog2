#include"sigaretta.hpp"

Sigaretta::Sigaretta(double nicotina,double catrame,double palladio,double tabacco,bool industriale,std::string marca)
{
	this->nicotina = nicotina;
	this->catrame = catrame;
	this->palladio = palladio;
	this->tabacco = tabacco;
	this->industriale = industriale;
	this->marca = marca;	
}
	
Sigaretta::~Sigaretta(){}
	
	//metodi set
	
inline void Sigaretta::setNicotina(double nicotina)
{
	this->nicotina = nicotina;
}
	
inline void Sigaretta::setCatrame(double catrame)
{
	this->catrame = catrame;
}
	
inline void Sigaretta::setPalladio(double palladio)
{
	this->palladio = palladio;
}
	
inline void Sigaretta::setTabacco(double tabacco)
{
	this->tabacco = tabacco;
}	
inline void Sigaretta::setIndustriale(bool industriale)
{
	this->industriale = industriale;
}	
inline void Sigaretta::setMarca(std::string marca)
{
	this->marca = marca;
}
	
	//metodi get
	
inline double Sigaretta::getNicotina() const
{
	return this->nicotina;
}	
inline double Sigaretta::getCatrame() const
{
	return this->catrame;
}	
inline double Sigaretta::getPalladio() const
{
	return this->palladio;
}	
inline double Sigaretta::getTabacco() const
{
	return this->tabacco;
}	
inline bool Sigaretta::getIndustriale() const
{
	return this->industriale;
}	
inline std::string Sigaretta::getMarca() const
{
	return this->marca;
}
