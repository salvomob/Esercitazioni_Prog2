#include"rettangolo.hpp"


Rettangolo::Rettangolo(int p1x,int p1y,int p3x,int p3y)
{
	this->p1x=p1x;
	this->p1y=p1y;
	this->p3x=p3x;
	this->p3y=p3y;
	this->p2x=this->p3x;
	this->p2y=this->p1y;
	this->p4x=this->p1x;
	this->p4y=this->p3y;
}

Rettangolo::~Rettangolo()
{}

/*
Il distruttore è superfluo, non c'è memory leak.
Rettangolo::~Rettangolo()
{
	std::cout << "ELIMINATO RETTANGOLO\n";
	delete [] &this->p1x;
	delete [] &this->p1y;
	delete [] &this->p2x;
	delete [] &this->p2y;
	delete [] &this->p3x;
	delete [] &this->p3y;
	delete [] &this->p4x;
	delete [] &this->p4y;
}*/

//metodi set

inline void Rettangolo::setP1X(int p)
{
	this->p1x = p;
} 

inline void Rettangolo::setP1Y(int p)
{
	this->p1y = p;
} 

inline void Rettangolo::setP2X(int p)
{
	this->p2x = p;
} 

inline void Rettangolo::setP2Y(int p)
{
	this->p2y = p;
} 

inline void Rettangolo::setP3X(int p)
{
	this->p3x = p;
} 

inline void Rettangolo::setP3Y(int p)
{
	this->p3y = p;
} 

inline void Rettangolo::setP4X(int p)
{
	this->p4x = p;
} 

inline void Rettangolo::setP4Y(int p)
{
	this->p4y = p;
}

//meotdi get 	

inline int Rettangolo::getP1X() const
{
	return this->p1x;
}

inline int Rettangolo::getP1Y() const
{
	return this->p1y;
}

inline int Rettangolo::getP2X() const
{
	return this->p2x;
}

inline int Rettangolo::getP2Y() const
{
	return this->p2y;
}

inline int Rettangolo::getP3X() const
{
	return this->p3x;
}

inline int Rettangolo::getP3Y() const
{
	return this->p3y;
}

inline int Rettangolo::getP4X() const
{
	return this->p4x;
}

inline int Rettangolo::getP4Y() const
{
	return this->p4y;
}

inline int Rettangolo::base(int p2x, int p1x) const
{
	return (p2x-p1x);
}

inline int Rettangolo::altezza(int p1y,int p4y) const
{
	return (p1y-p4y);
}

inline int Rettangolo::perimetro(int p1x,int p1y,int p3x,int p3y) const
{
	int b = this->base(p3x,p1x);
	int h = this->altezza(p1y,p3y);
	return ((b+h)*2);
}

inline int Rettangolo::area(int p1x,int p1y,int p3x,int p3y) const
{
	int b = this->base(p3x,p1x);
	int h = this->altezza(p1y,p3y);
	return (b*h);
}

std::ostream& operator<<(std::ostream& os, const Rettangolo& r)
{
	os << "P1(" << r.getP1X() << "," << r.getP1Y() << ")\n";
	os << "P2(" << r.getP2X()  << "," << r.getP2Y()  << ")\n";
	os << "P3(" << r.getP3X()  << "," << r.getP3Y()  << ")\n";
	os << "P4(" << r.getP4X()  << "," << r.getP4Y()  << ")\n";
	os << "Base : " << r.base(r.getP2X(),r.getP1X()) << "\n";
	os << "Altezza : "<< r.altezza(r.getP1Y(),r.getP4Y()) << "\n";
	os << "Perimetro : " << r.perimetro(r.getP1X(),r.getP1Y(),r.getP3X(),r.getP3Y()) << "\n";
	os << "Area : " << r.area(r.getP1X(),r.getP1Y(),r.getP3X(),r.getP3Y()) << "\n";
	return os;
}

std::istream& operator>>(std::istream& is, Rettangolo& r)
{
		int p1x=0;
		int p1y=0;
		int p2x=0;
		int p2y=0;
		int p3x=0;
		int p3y=0;
		int p4x=0;
		int p4y=0;
		
		std::string line = "";
		is>>line;
		//std::getline(in,line);
		//std::cout << line << std::endl;
		std::string delim = ";";
		std::string *tokens = new std::string[8];
		size_t pos = 0;
		int i = 0;
		std::string token;
		while ((pos = line.find(delim)) != std::string::npos)
		{
	   		token = line.substr(0, pos);
	   		tokens[i] = token; 
	   		line.erase(0, pos + delim.length());
	   		i++;	
		}
		tokens[i] = line;
		for(int i = 0; i< 8; i++)
		{
			switch(i){
				case 0:
				{
					p1x = (int)stoi(tokens[i]);
					continue;
				}
				case 1:
				{
					p1y = (int)stoi(tokens[i]);
					continue;
				}
				case 2:
				{
					p2x = (int)stoi(tokens[i]);
					continue;
				}
				case 3:
				{
					p2y = (int)stoi(tokens[i]);
					continue;
				}
				case 4:
				{
					p3x = (int) stoi(tokens[i]);
					continue;
				}
				case 5:
				{
					p3y = (int) stoi(tokens[i]);
					continue;
				}
				case 6:
				{
					p4x = (int) stoi(tokens[i]);
					continue;
				}
				case 7:
				{
					p4y = (int) stoi(tokens[i]);
					continue;
				}	
			}
		}
			
			r.setP1X(p1x);
			r.setP1Y(p1y);
			r.setP2X(p2x);
			r.setP2Y(p2y);
			r.setP3X(p3x);
			r.setP3Y(p3y);
			r.setP4X(p4x);
			r.setP4Y(p4y);		
			
			return is;
}
