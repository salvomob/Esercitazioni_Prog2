#include<iostream>
#include<cstdlib>
#include<cstring>
#include<climits>

using namespace std;

void stampa(int *s,int n);//funzione che stampa iterativamente gli elementi di un array dall'indice 0 fino all'indice n
void inizializza(int *s,int n,int x);//funzione che inizializza gli elementi di un array dall'indice 0 fino all'indice n con un dato valore x
template <class T> void swap(T* v, int i , int j);//funzione che scambia due elemnti di un array i -->  j
template <class T> T min(T* v,int n);//funzione che calcola il minimo di un array (sempre dalla posizione 0 alla posizione n)
template <class T> T max(T* v,int n);//funzione che calcola il massimo di un array (sempre dalla posizione 0 alla posizione n)

int main(){
	int *s;
	int n = 6;
	s = new int[n];
	for(int i = 0; i < n; i++){
		s[i] = rand() %10000;
	}
	stampa(s,n);
	cout << endl;
	cout << max(s,n) << endl;
	cout << min(s,n) << endl;
}


template <class T> void swap(T* v,int i , int j){
	T tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

template <class T> T min(T* v,int n){
	T min = v[0];
	for(int i = 0 ; i < n ; i++){
		if(min>=v[i]) min = v[i];
	}
	return min;
}

template <class T> T max(T* v,int n){
	T max = v[0];
	for(int i = 0 ; i < n ; i++){
		if(max<=v[i]) max = v[i];
	}
	return max;
} 



void inizializza(int *s,int n,int x){
	for(int i = 0; i < n ; i++) s[i] = x;
}


void stampa(int *s,int n){
	for(int i = 0; i < n; i++) cout << s[i] << " ";
}
