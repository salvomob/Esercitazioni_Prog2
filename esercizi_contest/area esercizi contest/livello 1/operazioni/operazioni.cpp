#include<iostream>
#include<fstream>

using namespace std;

int doit(int n, int m , char op);

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    for(int task = 0 ; task < 100 ; task++){
        int operazioni;
        in>>operazioni;
        for(int i = 0; i < operazioni ; i++){
            char op;
            int n1,n2;
            in>>n1;
            in>>op;
            in>>n2;
            out << doit(n1,n2,op) << " ";
        }    
        out << endl;
    }
    in.close();
    out.close();
}

int doit(int n,int m,char op){
    if(op == '+') return n+m;
    if(op == '-') return n-m;
    if(op == '*') return n*m;
}
