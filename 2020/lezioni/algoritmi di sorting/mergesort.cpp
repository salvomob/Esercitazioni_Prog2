/*
mergesort
*/
#include<iostream>

using namespace std;

template <class T> void stampa(T *v,int n);
template <class T> void scambia(T *v,int i,int j);
template <class T> void mergesort(T *v,int n);
template <class T> void merge(T *v, int n , int m);
int main(){
	int a[]={5,1,4,3,6,4,8,9,34,2};
	stampa(a,10);
	mergesort(a,10);
	stampa(a,10);
}

template <class T> void stampa(T *v,int n){
	for(int i=0;i<n;i++){
		cout << v[i] << " ";
	}
	cout<<endl;
}

template <class T>void scambia(T *v, int i , int j){
	T tmp = v[j];
	v[j]=v[i];
	v[i]=tmp;
}
template <class T> void mergesort(T *v, int n){//O(nlog(n)) complessità linearitmica
	if(n<=1) return;	
	int m = n/2;
	//v[0 . . m-1] +v[m . . n-1]
	mergesort(v,m);
	mergesort(v+m,n-m);
	merge(v,n,m);	
}
template <class T> void merge(T *v, int n , int m){//O(n)
	T b[n];
	int i,j,k;
	i = k = 0;
	j = m;
	while(i<m && j<n){
		if(v[i]<v[j]) b[k++]=v[i++];
		else b[k++]=v[j++];	
	}
	while(i<m) b[k++]=v[i++];
	while(j<n) b[k++]=v[j++];
	for(int i=0;i<n;i++) v[i]=b[i];	
}
