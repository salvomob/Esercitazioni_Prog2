#include<iostream>
using namespace std;

template <class T> void selectionsort(T *v, int n);
template <class T> void r_1selectionsort(T *v, int n);
template <class T> void r_2selectionsort(T *v, int n);
template <class T> void scambia(T *v,int i, int j);
template <class T> void stampa(T *v, int n);
int main(){
	int a[]={5,1,4,3,6,4,8,9,34,2};
	stampa(a,10);
	bubblesort(a,10);
	stampa(a,10);
}

template <class T> void selectionsort(T *v,int n){
	for(int i=0;i<n-1;i++){	
		int m=i;
		for(int j=i+1;j<n;j++)
			if(v[m]>v[j]) m=j;
		scambia (v,i,m);
	}
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
template <class T> void r_1selectionsort(T *v, int n){
	if(n<=1) return;
	int m=0;
	for(int i=0;i<n;i++) 
		if(v[m]>v[i]) m=i;
	scambia(v,0,m);
	r_1selectionsort(v+1,n-1);
}

template <class T> void r_2selectionsort(T *v, int n){
	if(n<=1) return;
	int m=0;
	for(int i=0;i<n;i++) 
		if(v[m]<v[i]) m=i;
	scambia(v,n-1,m);
	r_2selectionsort(v,n-1);
}
