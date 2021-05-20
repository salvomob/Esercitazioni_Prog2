#ifndef CERCHIO_H
#define CERCHIO_H

class Cerchio{
private:
	float raggio;
	
public:
	Cerchio(float r);
	
	float area();
	
	void stampa(std::ostream&);
	
};

#endif
