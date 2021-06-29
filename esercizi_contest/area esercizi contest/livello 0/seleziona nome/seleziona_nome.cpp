#include<iostream>
#include <fstream>

using namespace std;

void check(char *arr , int n, char a, char b,ostream& out);



int main(){
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    for(int task = 0; task < 100; task++){
        char a , b;
        in>>a;
        in>>b;
        int n1,n2,n3;
        in>>n1;
        char *nome1 = new char[n1];
        for(int i = 0; i < n1; i++) in>>nome1[i];
        check(nome1,n1,a,b,out);
        in>>n2;
        char* nome2 = new char[n2];
        for(int i = 0; i < n2; i++) in>> nome2[i];
        check(nome2,n2,a,b,out);
        in>>n3;
        char* nome3 = new char[n3];
        for(int i = 0; i < n3 ; i++) in>> nome3[i];
        check(nome3,n3,a,b,out);
        out << endl;
        
    }
        
    in.close();
    out.close();
}	

void check(char *arr , int n, char a, char b,ostream& out){
    if(arr[0] == a && arr[n-1]!=a){
        if(arr[0]!= b && arr[n-1]!=b)
        for(int i = 0; i < n; i++) out << arr[i];
        out << " ";
    }
    else if(arr[0]!= a && arr[n-1]==a){
        if(arr[0]!= b && arr[n-1]!=b)
        for(int i = 0; i < n; i++) out << arr[i];
        out << " ";
    }
    else return;
    
}
