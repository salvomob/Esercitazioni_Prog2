#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    for(int task = 0 ; task < 100 ; task++){
        double *a;
        int n;
        in>> n;
        a = new double[n];
        for(int i = 0 ; i < n ; i++){
            in>> a[i];
        }
        for(int i = 0; i < n ; i++){
            out << (int) a[i] << " ";
        }
        out << endl;
    }
    in.close();
    out.close();
}
