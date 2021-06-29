#include<iostream>
#include"stampa.cpp"
using namespace std;


 int max(int *a, int n);
int main(){
 	int b[]={1,2,3,4,5,6};
	stampa(b,6);	
	cout << max(b,6)<< endl;

}

int max(int a[],int n){
	int max=a[0];
	for(int i=0;i<n;i++){			
		if(a[i]>max) max = a[i];		
	}
	return max;
}

