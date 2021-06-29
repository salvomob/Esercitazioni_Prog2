#include<iostream>
#include<fstream>
#include"BST.cpp"

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    for(int task = 0 ; task < 100 ; task++){
        string tipo;
        in>>tipo;
        int n;
        in>>n;
        int m;
        in>>m;
        if(tipo == "int"){
            BST<int> *t = new BST<int>();
            for(int i = 0; i < n ; i++){
                char c,b;
                in>>c;
                in>>b>>b>>b;
                if(c == 'i'){
                    int *e = new int(0);
                    in>> *e;
                    t->ins(*e);
                }
                else{
                    in>>b;
                    int f;
                    in>>f;
                    t->canc(f);
                }
            }
            for(int i = 0; i < m; i++){
                int numero;
                in>> numero;
                if(t->predecessore(numero) == 0) out << -1 << " ";
                else out << t->predecessore(numero) << " ";
            }
            out << endl;
        }
        else{
            BST<double> *t = new BST<double>();
            for(int i = 0 ; i < n ; i++){
                char c,b;
                in>> c;
                in>>b>>b>>b;
                if(c == 'i'){
                    double *e = new double(0);
                    in>> *e ;
                    t->ins(*e);
                }
                else{
                    in>>b;
                    double f;
                    in>>f;
                    t->canc(f);
                }
            }
            for(int i = 0; i < m ; i++){
                double numero;
                in>>numero;
                if(t->predecessore(numero) == 0) out << -1 << " ";
                else out << t->predecessore(numero) << " ";
            }
            out << endl;
        }
    }
    in.close();
    out.close();
}
