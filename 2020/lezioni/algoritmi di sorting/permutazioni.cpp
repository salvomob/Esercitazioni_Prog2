#include<iostream>
using namespace std;

template <class T> void permutazioni(T *v,int j,int n);
template <class T> void swap(T *v,int i , int j);
int main(){
	char a[]={'a','e','i','o','u'};
	permutazioni(a,1,5);
}

template <class T> void permutazioni(T *v,int j,int n){
	if(j==n){
		for(int i=0;i<n;i++) cout << v[i];
		cout << endl;
	}
	//j<n
	for(int i=j;i<=n;i++){
		swap(v,i,j);
		permutazioni(v,j+1,n);
		swap(v,j,i);	
	}
}

template <class T> void swap(T *v, int i,int j){
	T tmp = v[j];
	v[j]=v[i];
	v[i]=tmp;
}

