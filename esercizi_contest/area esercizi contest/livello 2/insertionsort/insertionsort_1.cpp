#include<iostream>
#include<fstream>

using namespace std;

template <class T> int insertionsort(T *v,int n);

template <class T> void scambia(T *v, int i, int j);

int main(){
    /*ifstream in("input.txt");
    ofstream out("output.txt");
    for(int task = 0; task < 100 ; task++){
        int n;
        in>>n;
        int *a;
        a = new int[n];
        for(int i= 0; i < n; i++){
            in>>a[i];
        }
        out << insertionsort(a,n) << endl;
    }
    in.close();
    out.close();*/
    
    int a[] = {1,20,11,6,5,13,17,16,18,19,3};
    cout << insertionsort(a,11) << endl;
}

template <class T> int insertionsort(T *v,int n){
	int counter = 0;
	for(int i=0;i<n;i++){
		int j=i;
		while(j>0 && v[j-1]>v[j]){
			cout << v[j] << "<-"  << v[j-1] << "\n";
			scambia(v,j,j-1);
			
			counter++;
			j--;		
		}
	}
	return counter;
}

template <class T> void scambia(T *v, int i, int j){
	T tmp = v[j];
	v[j]=v[i];
	v[i]=tmp;
}
