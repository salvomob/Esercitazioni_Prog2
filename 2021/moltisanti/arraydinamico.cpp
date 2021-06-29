//Implementare una classe che simuli il comportamento di un array in maniera dinamica (int)
//if(dimensione == dimensione_massima) dimensione_massima = dimensione_massima*2 ------ if(dim < dim_max/2) ->dim_max = dim_max/2
//eliminazione -->> eliminare elemento e shifting a sx dei rimanenti
// restituisci elemento i-esimo -->> attenzione a dimensione massima e dimensione)
// restituisci indice elemento j

#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;

template <class T> class ArrayDinamico{
private:
	int n;
	int dim_max;
	T *array;
	
public:	
	ArrayDinamico(int _dim_max){
		this->dim_max =  _dim_max;
		this->n = 0;
		array = new T[dim_max];
	}
	
	int getMaxDim(){
		return dim_max;
	}
	
	void setDimMax(int _dim_max){
		this->dim_max = _dim_max;
	}
	
	void print(){
		cout << "Array dinamico di dimensione massima = " << dim_max << endl;
		for(int i = 0; i < n ; i++){
			cout << array[i] << " ";
		}
		cout << endl;
	}
	
	ArrayDinamico& ins(T k){
		if(n == dim_max){
			dim_max *= 2;
			T* tmp = new T[dim_max];
			for(int i = 0; i < n; i++){
				tmp[i] = array[i];
			}
			T *toDelete = array;
			array = tmp;
			delete [] toDelete;
		}
		array[n++] = k;
		return *this;
	}
	
	ArrayDinamico& canc(T k){
		for(int i = 0; i < n; i++){
			if(array[i]==k){
				for(int j = i; j < n-1; j++){	
					array[j] = array[j+1];
					cout << "shifto" << endl;	
				}	
			}
		}
		n--;
		if(n<(dim_max/2)){ 
			dim_max /= 2;
			T *tmp = new T[dim_max];
			for(int i = 0; i < n; i++){
				tmp[i] = array[i];
			}
			T *toDelete = array;
			array = tmp;
			delete [] toDelete;
			return *this;
		}
		return *this;
	}
};

int main(){
	ArrayDinamico<int> ad(10);
	ad.print();
	cout << ad. getMaxDim() << endl;
	ad.ins(5).ins(6).ins(50).ins(65).ins(12).ins(43).ins(58).ins(87).ins(23);
	ad.print();
	ad.canc(23).canc(43);
	ad.print();
}
