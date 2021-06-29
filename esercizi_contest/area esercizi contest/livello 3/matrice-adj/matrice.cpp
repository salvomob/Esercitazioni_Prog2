#include<iostream>
#include<fstream>
#include"grafo.cpp"

using namespace std;

template <class T> void sort(T *v,int n);
template <class T> void scambia(T *v,int i, int j);


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
            int *array = new int[n];
            for(int i = 0; i < n ; i++){
                int a;
                in>>a;
                array[i] = a;
                g->addNode(array[i]);
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
            sort(array,n);
            for(int i = 0; i < n ; i++){
            	g->stampaUscenti(array[i],out);
            	out << " ";
            }  
               
        }
        
        if(tipo=="char"){
            Grafo<char> *g = new Grafo<char>();
            char *array = new char[n];
            for(int i = 0; i < n ; i++){
                char a;
                in>>a;
                array[i] = a;
                g->addNode(array[i]);
            }
            for(int i = 0; i < m ; i++){
                char c,a,b;
                in>>c;
                in>>a;
              
                in>>b;
                in>>c;
                g->addEdge(a,b);
            }
            sort(array,n);
            for(int i = 0; i < n ; i++){
            	g->stampaUscenti(array[i],out);
            	out << " ";
            } 
            
        }
        
        if(tipo == "bool"){
            Grafo<bool> *g = new Grafo<bool>();
            bool *array = new bool[n];
            for(int i = 0; i < n ;i++){
                bool a;
                in>>a;
                array[i] = a;
                
                g->addNode(array[i]);
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
            sort(array,n);
			for(int i = 0; i < n ; i++){
            	g->stampaUscenti(array[i],out);
            	out << " ";
            }
           
        }
        
        if(tipo == "double"){
            Grafo<double> *g = new Grafo<double>();
            double *array = new double[n];
            for(int i = 0; i < n; i++){
                double a ; 
                in>>a ;
                array[i] = a;
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
            sort(array,n);
			for(int i = 0; i < n ; i++){
            	g->stampaUscenti(array[i],out);
            	out << " ";
            } 
            
        }
        out << endl;
        
    }
    in.close();
    out.close();
}

template <class T> void sort(T *v,int n){
	for(int i=0;i<n-1;i++){	
		int m=i;
		for(int j=i+1;j<n;j++)
			if(v[m]>v[j]) m=j;
		scambia (v,i,m);
	}
}

template <class T> void scambia(T *v, int i, int j){
	T tmp = v[j];
	v[j]=v[i];
	v[i]=tmp;
}
