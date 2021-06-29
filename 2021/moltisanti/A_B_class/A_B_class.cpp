/*
A:
+pippo :int
- paperino : int
# pluto :int
----
+ print : void
#somma() : int

B:
#print () : void "sono pluto"
*/
#include<iostream>
using namespace std;
class A{

private:

	int paperino;
	
protected:

	int pluto;
	int somma(){
		return pippo+paperino+pluto;
	}		
	
		
public:
	
	int pippo;

	A(int pluto,int paperino,int pippo){
		this->pluto = pluto;
		this->paperino = paperino;
		this->pippo = pippo;
	};
	
	
	
	void print(){
		cout << "la somma e' : " << somma() <<endl;
		cout << "pippo : " << pippo << " paperino : " << paperino << " pluto : " << pluto<< endl;
	}
	
};

class B : public A{

	public:
		B(int pippo,int pluto,int paperino) : A(pippo,pluto,paperino){}
	
	
	void print(){
		cout << "sono la classe B" << endl ;
	}
};

int main(){
	A a(1,2,3);
	B b(1,2,3);
	//a.somma(); errore, scope protected !!
	a.print();
	b.print();
}
