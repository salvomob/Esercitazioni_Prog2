#include<iostream>
using namespace std;

template <class T> void bubblesort(T *v, int n);
template <class T> void scambia(T *v,int i, int j);
template <class T> void stampa(T *v, int n);


template <class T> void bubblesort(T *v,int n){
	int i,k;
	int tmp;
	for(int i=0;i<n-1;i++)
		for(k=0;k<n-1-i;k++)
			if(v[k]>v[k+1]) 
				scambia(v,k,k+1);
}

template <class T> void stampa(T *v,int n){
	for(int i=0;i<n;i++){
		cout<< v[i] << " ";		
	}
	cout << endl;
}

template <class T> void scambia(T *v, int i, int j){
	T tmp = v[j];
	v[j]=v[i];
	v[i]=tmp;
}

int main(){
	int a[]={1,3,2,4,5,7,6,8,9};
	stampa(a,9);
	bubblesort(a,9);
	stampa(a,9);
}
