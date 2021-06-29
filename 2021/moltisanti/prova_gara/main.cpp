#include"veicolo.h"
#include"gara.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;

/*

FUNZIONA PERFETTAMENTE!!!

*/

int main(){

	Veicolo v(4);
	v.setAccM(25.0f);
	v.setVelM(200.0f);
	
	
	
	srand(42);
	for(int i = 0; i < 1000;i++){
		int scelta = rand()%2;
		if(scelta == 1){
			v.accelera();
			/*cout << v.getAcc() << " acc[" << i << "]" << endl;
			cout << v.getVel() << " vel[" << i << "]" << endl;*/
			v.move();
			/*cout << v.getAcc() << " acc[" << i << "]" << endl;
			cout << v.getVel() << " vel[" << i << "]" << endl;*/
			//cout <<"Posizione finale dopo "<< i+1 << " step : " << v.getPosF() << endl; 
		} 
		else{
			v.decelera();
			/*cout << v.getAcc() << " acc[" << i << "]" << endl;
			cout << v.getVel() << " vel[" << i << "]" << endl;*/
			v.move();
			/*cout << v.getAcc() << " acc[" << i << "]" << endl;
			cout << v.getVel() << " vel[" << i << "]" << endl;*/
			//cout <<"Posizione finale dopo "<< i+1 << " step : " << v.getPosF() << endl;
		} 
	}
	
	cout << "Posizione finale primo veicolo " << v.getPosF() << "\n"; 
	
	Veicolo v1(4);
	v1.setAccM(25.0f);
	v1.setVelM(200.0f);
	
	
	
	srand(81);
	for(int i = 0; i < 1000;i++){
		int scelta = rand()%2;
		if(scelta == 1){
			v1.accelera();
			/*cout << v.getAcc() << " acc[" << i << "]" << endl;
			cout << v.getVel() << " vel[" << i << "]" << endl;*/
			v1.move();
			/*cout << v.getAcc() << " acc[" << i << "]" << endl;
			cout << v.getVel() << " vel[" << i << "]" << endl;*/
			//cout <<"Posizione finale dopo "<< i+1 << " step : " << v1.getPosF() << endl; 
		} 
		else{
			v1.decelera();
			/*cout << v.getAcc() << " acc[" << i << "]" << endl;
			cout << v.getVel() << " vel[" << i << "]" << endl;*/
			v1.move();
			/*cout << v.getAcc() << " acc[" << i << "]" << endl;
			cout << v.getVel() << " vel[" << i << "]" << endl;*/
			//cout <<"Posizione finale dopo "<< i+1 << " step : " << v1.getPosF() << endl;
		} 
	}
	cout << "Posizione finale secondo veicolo " << v1.getPosF() << "\n"; 
	
	Veicolo v2(4);
	v2.setAccM(25.0f);
	v2.setVelM(200.0f);
	
	
	
	srand(69);
	for(int i = 0; i < 1000;i++){
		int scelta = rand()%2;
		if(scelta == 1){
			v2.accelera();
			/*cout << v.getAcc() << " acc[" << i << "]" << endl;
			cout << v.getVel() << " vel[" << i << "]" << endl;*/
			v2.move();
			/*cout << v.getAcc() << " acc[" << i << "]" << endl;
			cout << v.getVel() << " vel[" << i << "]" << endl;*/
			//cout <<"Posizione finale dopo "<< i+1 << " step : " << v2.getPosF() << endl; 
		} 
		else{
			v2.decelera();
			/*cout << v.getAcc() << " acc[" << i << "]" << endl;
			cout << v.getVel() << " vel[" << i << "]" << endl;*/
			v2.move();
			/*cout << v.getAcc() << " acc[" << i << "]" << endl;
			cout << v.getVel() << " vel[" << i << "]" << endl;*/
			//cout <<"Posizione finale dopo "<< i+1 << " step : " << v2.getPosF() << endl;
		} 
	}
		cout << "Posizione finale terzo veicolo " << v2.getPosF() << "\n"; 
}
