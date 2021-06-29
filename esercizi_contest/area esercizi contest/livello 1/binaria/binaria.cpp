#include<iostream>
#include<fstream>
#include<bitset>

using namespace std;

string toB(int n);

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    for(int task = 0; task < 100; task++){
        int n;
        int *a;
        in>>n;
        a = new int[n];
        for(int i = 0; i < n; i++){
            in>>a[i];
        }
        for(int i = 0; i < n; i++){
            bitset<8> bin_x(a[i]);
            out << bin_x<< " ";
        }
        out << endl;
    }
    in.close();
    out.close();
}

string toB(int n){
    string b = "";
    while(n>0){
        if(n%2==0)
            b ='0'+b;
        else
            b = '1'+b;
        n=n/2;        
    }
    return b;
}
