#include<iostream>
using namespace std;
/*
quicksort Hoare->1961
*/

template <class T> void stampa(T *v,int n);
template <class T> void scambia(T *v,int i,int j);
template <class T> void quicksort(T *v,int n);
template <class T> int partition(T *v,int n);

int main(){
	int a[]={6,4,3,2,7,1,8,9,0,5};
	stampa(a,10);
	quicksort(a,10);
	stampa(a,10);	
}

template <class T> void stampa(T *v,int n){
	for(int i=0;i<n;i++){
		cout << v[i] << " ";
	}
	cout<<endl;
}

template <class T> void scambia(T *v, int i , int j){
	T tmp = v[j];
	v[j]=v[i];
	v[i]=tmp;
}

template <class T> void quicksort(T *v, int n){
	if(n<=1) return;
	int m = partition(v,n);
	quicksort(v,m+1);
	quicksort(v+m+1,n-(m+1));
}
template <class T> int partition(T *v,int n){
	T x = v[0];//elemento pivot
	int i=-1;
	int j=n;
	do{
		do i++; while(v[i]<x);
		do j--; while(v[j]>x);
		if(i<j) scambia(v,i,j);
	}while(i<j);
	return j;
}

