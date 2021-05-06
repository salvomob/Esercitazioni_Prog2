#ifndef QUADRATO_H
#define QUADRATO_H

class Quadrato{

private:

	int lato;
	
public:
	
	Quadrato(int l){
		this->lato = l;
	}
	
	int perimetro(){
		return(4*this->lato);
	}
	
	int area(){
		return (this->lato*this->lato);
	}
		
};

#endif
