#include<iostream>
using namespace std;

void stampa(int[],int);
void inizializza(int A[],int n,int x);

int main(){
	int A[]={1,2,3,4,5,6};
	stampa(A,6);
	inizializza(A,6,1);
	stampa(A,6);
}

void stampa(int A[],int n){
	for(int i=0;i<n;i++){
		cout << A[i] << " ";
	}
	cout<<endl;
}

void inizializza(int A[], int n , int x){
	for(int i=0;i<n;i++){
		A[i]=x;
	}
}
