#include<iostream>
using namespace std;

template <class T> void insertionsort(T *v, int n);
template <class T> void r_insertionsort(T *v,int n);
template <class T> void scambia(T *v,int i, int j);
template <class T> void stampa(T *v, int n);
template <class T> void backInsertionSort(T* v,int n);
int main(){
	int a[]={5,1,4,3,6,4,8,9,34,2};
	stampa(a,10);
	backInsertionSort(a,10);
	stampa(a,10);
}

template <class T> void insertionsort(T *v,int n){
	for(int i=0;i<n;i++){
		int j=i;
		while(j>0 && v[j-1]>v[j]){
			scambia(v,j,j-1);
			j--;		
		}
	}
}
	
template <class T> void backInsertionSort(T* v,int n){
	for(int i=0;i<n;i++){
		int j=i;
		while(j>0 && v[j-1]<v[j]){
			scambia(v,j,j-1);
			j--;		
		}
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

template <class T> void r_insertionsort(T *v,int n){
	if(n<=1) return;
	r_insertionsort(v,n-1);
	int j= n-2;
	while(j>=0 && v[j]>v[j+1]){
		scambia(v,j,j+1);
		j--;
	}
}
