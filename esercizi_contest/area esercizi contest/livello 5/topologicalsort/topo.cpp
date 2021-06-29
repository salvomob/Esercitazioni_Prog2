#include<iostream>
#include<fstream>
#include"grafo.cpp"

using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    for(int task = 0 ; task < 100; task++){
        int n,m;
        in>>n>>m;
        string tipo;
        in>>tipo;
        if(tipo == "int"){
            Grafo<int> *g = new Grafo<int>();
            for(int i = 0; i < n ; i++){
                int a;
                in>>a;
                g->addNode(a);
            }
            for(int i = 0; i < m; i++){
                char c;
                int a,b;
                in>>c;
                in>>a;
                in>>b;
                in>>c;
                g->addEdge(a,b);
            }
            g->topologicalSort(out);
        }
        
        if(tipo=="char"){
            Grafo<char> *g = new Grafo<char>();
            for(int i = 0; i < n ; i++){
                char a;
                in>>a;
                g->addNode(a);
            }
            for(int i = 0; i < m ; i++){
                char c,a,b;
                in>>c;
                in>>a;
                in>>b;
                in>>c;
                g->addEdge(a,b);
            }
            g->topologicalSort(out);
        }
        
        if(tipo == "bool"){
            Grafo<bool> *g = new Grafo<bool>();
            for(int i = 0; i < n ;i++){
                bool a;
                in>>a;
                g->addNode(a);
            }
            for(int i = 0; i < m;i++){
                char c;
                bool a,b;
                in>>c;
                in>>a;
                in>>b;
                in>>c;
                g->addEdge(a,b);
            }
            g->topologicalSort(out);
        }
        
        if(tipo == "double"){
            Grafo<double> *g = new Grafo<double>();
            for(int i = 0; i < n; i++){
                double a ; 
                in>>a ;
                g->addNode(a);
            }
            for(int i = 0; i < m; i++){
                char c;
                double a,b;
                in>>c;
                in>>a;
                in>>b;
                in>>c;
                g->addEdge(a,b);
            }
            g->topologicalSort(out);
        }
        
        out << endl;
    }
    in.close();
    out.close();
}
