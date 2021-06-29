/*

Overloading << e >> per una data classe

*/

#include<iostream>
#include<fstream>

using namespace std;

class Punto{
	double x,y;
	
	public:
	Punto() : Punto(0.0,0.0){}
	
	Punto(double x, double y){
		this->x = x;
		this->y = y;
	}
	
	friend istream& operator>>(istream& in, Punto& p){
		in>> p.x;
		in>>p.y;
		return in;
	}
	
	friend ostream& operator<<(ostream& out, const Punto& p){
		out << "P: x->" << p.x << ", y->" << p.y;
		return out;
	}
	
};

int main(){
	ifstream in("input.txt");
	Punto p1,p2,p3,p4;
	
	in>>p1>>p2>>p3>>p4;
	
	
	cout<< "1:{"<< p1 << "}\n 2:{" << p2 << "}\n 3:{" << p3 << "}\n 4:{" << p4  <<"}"<<endl; ;
}


