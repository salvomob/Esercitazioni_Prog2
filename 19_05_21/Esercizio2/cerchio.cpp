#include"cerchio.h"

inline Cerchio::Cerchio(float r)
{
	this->raggio = r;
}

inline float Cerchio::area()
{
	return (this->raggio*this->raggio*3.14);	
}

inline void Cerchio::stampa(std::ostream& out)
{
	out << this->area() << " ";
} 

