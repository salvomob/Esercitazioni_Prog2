#include<iostream>
#include<fstream>

using namespace std;

int index(int *a,int n,int f);

int main(){
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    for(int task = 0; task < 100 ; task++){
        int n;
        int f;
        int *a;
        in>>n;
        in>>f;
        a = new int[n];
        for(int i=0; i < n; i++){
            in>>a[i];
        }
        out << index(a,n,f)<< endl;
        
    }
    in.close();
    out.close();
}

int index(int *a,int n,int f){
    for(int i = 0; i < n ; i++){
        if(a[i] == f) return i+1;
    }
    return 0;
}
