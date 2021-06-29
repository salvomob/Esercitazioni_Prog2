#include<iostream>
#include<fstream>
#include"BST.cpp"

using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    for(int task = 0; task < 100 ; task++){
        string tipo;
        int n;
        in>>tipo;
        in>>n;
        
        if(tipo == "int"){
            BST<int> *t = new BST<int>();
            for(int i = 0; i < n; i++ ){
                char c,b;
                in>>c;
                in>>b>>b>>b;
                if(c=='i'){
                    int *e = new int(0);
                    in>>*e;
                    t->ins(*e);
                }
                else{
                    in>>b;
                    int f;
                    in>>f;
                    t->canc(f);
                }
            }
            int k;
            in>>k;
            out << t->prof(k);
        }
        else{
            BST<double> *t = new BST<double>();
             for(int i = 0; i < n; i++ ){
                char c,b;
                in>>c;
                in>>b>>b>>b;
                if(c=='i'){
                    double *e = new double(0);
                    in>>*e;
                    t->ins(*e);
                }
                else{
                    in>>b;
                    double f;
                    in>>f;
                    t->canc(f);
                }
            }
            double k;
            in>>k;
            out << t->prof(k);    
        }
        out << endl;
    }
    in.close();
    out.close();
}
