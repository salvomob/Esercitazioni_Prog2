#include<fstream>
#include<iostream>

#define MAXN 20

using namespace std;

template <class T> class Graph{
private:
	bool **adj;
	T **k;
	int n,m,current;
	
	int _search(T key){
		for(int i=0;i<n;i++){
			if(*k[i] == key) return i;
		}
		return -1;
	}
	
public:
	Graph(){
		n=0;
		m=0;
		adj = new bool*[MAXN];
		for(int i=0; i<MAXN; i++)
           		adj[i] = new bool[MAXN];
		k = new T*[MAXN];
	}
	
	Graph<T>& addNode(T key){
		k[n] = new T(key);
		n++;
		for(int i=0;i<n;i++) adj[n][i]=adj[i][n] = 0;
		return *this;	
	}
	
	Graph<T>& addEdge(T key1,T key2){
		int i = _search(key1);
		int j = _search(key2);
		if(i<0 || j<0) return *this;
		adj[i][j] = 1;
		m++;
		return *this;
	}
	
	void adjSet(T key,ostream& out){
		int i= _search(key);
		if(i<0) return;
		out << "("<< *k[i] << ",";
		for(int j=0;j<n;j++){
			if(adj[i][j] == 1)
				out<< *k[j];	
		}
		out << ")";
	}
};

int main(){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	for(int task = 0; task < 100; task++) {
		int n,m,e,f;
		double o,h;
		string tipo;
		char c,x,y;
		int *a = new int[n];
		char *l= new char[n];
		double *d= new double[n];
		in>>n;
		in>>m;
		in>>tipo;
		if(tipo == "int"){
			Graph<int> *g = new Graph<int>();
			for(int i=0;i<n;i++){
				in>>a[i];
				g->addNode(a[i]);
			}
			for(int i=0;i<m;i++){
				in>>c;
				in>>e;
				in>>f;
				in>>c;
				g->addEdge(e,f);
			}
			for(int i=0;i<n;i++){
				g->adjSet(a[i],cout);
			}
			out << endl;
		}
		if(tipo == "double"){
			Graph<double> *g = new Graph<double>();
			for(int i=0;i<n;i++){
				in>>d[i];
				g->addNode(d[i]);
			}
			for(int i=0;i<m;i++){
				in>>c;
				in>>o;
				in>>h;
				in>>c;
				g->addEdge(o,h);
			}
			for(int i=0;i<n;i++){
				g->adjSet(d[i],out);
			}
			out << endl;
		}
		if(tipo == "char"){
			Graph<char> *g = new Graph<char>();
			for(int i=0;i<n;i++){
				in>>l[i];
				g->addNode(l[i]);
			}
			for(int i=0;i<m*2;i++){
				in>>c;
				in>>x;
				in>>y;
				in>>c;
				g->addEdge(x,y);
			}
			for(int i=0;i<n;i++){
				g->adjSet(l[i],out);
			}
			out << endl;
		}
		in.close();
		out.close();
		
	}
	in.close();
	out.close();
	
	/*Graph<int> *g = new Graph<int>;
	g->addNode(1).addNode(2).addNode(3).addNode(4);
	g->addEdge(1,2).addEdge(1,3);
	g->addEdge(2,3);
	g->adjSet(1,cout);
	cout << " ";
	g->adjSet(2,cout);
	cout << endl;*/
	
}
