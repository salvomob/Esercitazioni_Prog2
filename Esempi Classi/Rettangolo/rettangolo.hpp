#ifndef RETTANGOLO_HPP
#define RETTANGOLO_HPP

class Rettangolo{

private:
	int p1x;
	int p1y;
	int p2x;
	int p2y;
	int p3x;
	int p3y;
	int p4x;
	int p4y;

public:

	Rettangolo(){}	
	
	Rettangolo(int p1x,int p1y,int p3x,int p3y);
	
	~Rettangolo();
	
	//metodi set
	
	void setP1X(int);

	void setP1Y(int);

	void setP2X(int);

	void setP2Y(int);

	void setP3X(int);

	void setP3Y(int);

	void setP4X(int);

	void setP4Y(int);
	
	
	//metodi get
	
	int getP1X() const;
	
	int getP1Y() const;
	
	int getP2X() const;
	
	int getP2Y() const;
	
	int getP3X() const;
	
	int getP3Y() const;

	int getP4X() const;
	
	int getP4Y() const;

	//metodi aux
	
	int base(int , int) const;
	
	int altezza(int , int) const;
	
	int perimetro(int , int , int , int) const;
	
	int area(int , int , int , int) const;
	
	
};


std::ostream& operator<<(std::ostream& os, const Rettangolo& r);

std::istream& operator>>(std::istream& is, Rettangolo& r);

#endif
