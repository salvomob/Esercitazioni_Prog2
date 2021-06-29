#include<iostream>
#include<fstream>
#include"grafo.cpp"

using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    for(int task = 0; task < 100 ; task++){
        int n,m;
        in>>n;
        in>>m;
        string tipo;
        in>>tipo;
        if(tipo == "int"){
            char c;
            Grafo<int> *grafo = new Grafo<int>();
            int *a;
            a = new int[n];
            for(int i = 0; i < n ; i++) in>>a[i];
            for(int i = 0; i < n-1 ; i++) cout << a[i] << " ";
           // cout << a[n] << endl;//grafo->addNode(a[i]);
            for(int i = 0 ; i < m ; i++){
                in>>c;
                int a1,a2;
                in>>a1;
              
                in>>a2;
                in>>c;
                grafo->addEdge(a1,a2);
            }
            grafo->dfs1(out);  
        }
        
        if(tipo == "double"){
            char c;
            Grafo<double> *grafo = new Grafo<double>();
            double *a;
            a = new double[n];
            for(int i = 0; i < n ; i++) in>>a[i];
            for(int i = 0; i < n ; i++) grafo->addNode(a[i]);
            for(int i = 0 ; i < m ; i++){
                in>>c;
                double a1,a2;
                in>>a1;
               
                in>>a2;
                in>>c;
                grafo->addEdge(a1,a2);
            }
            grafo->dfs1(out); 
            
        }
        
        if(tipo == "char"){
            char c;
            Grafo<char> *grafo = new Grafo<char>();
            char *a;
            a = new char[n];
            for(int i = 0; i < n ; i++) in>>a[i];
            for(int i = 0; i < n ; i++) grafo->addNode(a[i]);
            for(int i = 0 ; i < m ; i++){
                in>>c;
                char a1,a2;
                in>>a1;
              
                in>>a2;
                in>>c;
                grafo->addEdge(a1,a2);
            }
             grafo->dfs1(out);  
        }
        out << endl;
    }
    in.close();
    out.close();
}

