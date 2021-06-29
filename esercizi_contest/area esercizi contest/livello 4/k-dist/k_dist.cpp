#include<iostream>
#include<fstream>
#include"BST.cpp"

using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    for(int task = 0; task < 100; task++){
        string tipo;
        int n;
        int k;
        in>>tipo;
        in>>n;
        in>>k;
        if(tipo == "int"){
            BST<int> *tree = new BST<int>();
            for(int i = 0; i < n; i++){
                char c,b;
                in>>c;
                in>>b>>b>>b;
                if(c == 'i'){
                    int *e = new int(0);
                    in>> *e;
                    tree->ins(*e);
                }
                else{
                    in>>b;
                    int f;
                    in>>f;
                    tree->canc(f);
                }
            }
            tree->printlevel(k,out);
        }
        else{
            BST<double> *tree = new BST<double>();
            for(int i = 0; i < n ; i++){
                char c,b;
                in>>c;
                in>>b>>b>>b;
                if(c == 'i'){
                    double *e = new double(0);
                    in>> *e;
                    tree->ins(*e);
                }
                else{
                    in>>b;
                    double f;
                    in>>f;
                    tree->canc(f);
                }
            }
            tree->printlevel(k,out);
            }    
        }
    in.close();    
    out.close();
}
