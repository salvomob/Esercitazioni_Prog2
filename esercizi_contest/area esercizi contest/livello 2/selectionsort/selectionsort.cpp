#include<iostream>
#include<fstream>

using namespace std;

template <class T> void scambia(T *v,int i, int j);
template <class T> int selectionsort(T *v, int n);

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    for(int task = 0; task < 3 ; task++){
        int n;
        in>>n;
        int *a;
        a = new int[n];
        for(int i = 0; i < n; i++){
            in>>a[i];
        }
        cout << selectionsort(a,n)<<endl; 
    }
    in.close();
    out.close();
}

template <class T> int selectionsort(T *v,int n){
	int spostamenti = 0;
	int somma = 0;
	int i;
	int m;
	for(i=0;i<n-1;i++){	
		 m=i;
		for(int j=i+1;j<n;j++)
			if(v[m]>v[j]) m=j;
		spostamenti = m - i;
		cout << spostamenti << endl;
        somma += spostamenti;	
		scambia (v,i,m);
	}
	return somma;
}
template <class T> void scambia(T *v, int i, int j){
	T tmp = v[j];
	v[j]=v[i];
	v[i]=tmp;
}

