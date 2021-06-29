#include<iostream>
#include<fstream>

using namespace std;

template <class T> T massimo(T* v,int n);

int main(){
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    for(int task = 0 ; task < 100 ; task++){
        int n;
        in >> n;
        string *a;
        a = new string[n];
        for(int i = 0; i < n;i++){
            in>> a[i];
        }
       out << massimo(a,n) << endl;
    }
    in.close();
    out.close();
}


template <class T> T massimo(T* v,int n){
    T max = v[0];
    for(int i = 0; i < n ; i++){
        if(v[i]>max)
            max = v[i];
    }
    return max;
}
