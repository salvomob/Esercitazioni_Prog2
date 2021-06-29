#include<iostream>
#include<fstream>

using namespace std;

template <class T> int mergesort(T *v,int n);
template <class T> int merge(T *v, int n , int m);
template <class T> void scambia(T *v,int i,int j);

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    for (int task  =0 ; task < 100 ; task++){
        int n;
        in>>n;
        int *a;
        a = new int[n];
        for(int i = 0; i < n ;i++){
            in>>a[i];
        }
       out <<  mergesort(a,n)<<endl;
    }
    in.close();
    out.close();
}

template <class T>void scambia(T *v, int i , int j){
	T tmp = v[j];
	v[j]=v[i];
	v[i]=tmp;
}
template <class T> int mergesort(T *v, int n){//O(nlog(n)) complessità linearitmica
	if(n<=1) return 0;	
	int m = n/2;
	//v[0 . . m-1] +v[m . . n-1]
	int a = mergesort(v,m);
	int b = mergesort(v+m,n-m);
	return merge(v,n,m)+a+b;	
}
template <class T> int merge(T *v, int n , int m){//O(n)
	T b[n];
	int counter = 0;
	int i,j,k;
	i = k = 0;
	j = m;
	while(i<m && j<n){
		if(v[i]<v[j]){
		    b[k++]=v[i++];
		    counter++;
		} 
		else b[k++]=v[j++];	
	}
	while(i<m){ 
	    b[k++]=v[i++];
	} 
	while(j<n) b[k++]=v[j++];
	for(int i=0;i<n;i++) v[i]=b[i];	
	return counter;
}
