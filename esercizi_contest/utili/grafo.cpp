/*
STRUTTURA DATI DI TIPO GRAFO IMPLEMENTATA ATTRAVERSO UNA MATRICE DI ADIACENZA

La struttura presenta i metodi visti a lezione. Essi saranno implementati attraverso delle funzioni di scope privato (richiamabili solo all'interno della sezione pubblica della classe stessa) che semplificano l'utilizzo all'utente finale. Essi sono :
- _bfs()
- _printShortestPath(s)
- _dfsVisit(s)
- _cycleTest(s) --->>> mio --->>> funziona --->>> V

I metodi pubblici accessibili all'utente finale nella seaione pubblica della classe sono :

- addNode(key)
- cancNode(key)
- addEdge(key1,key2)
- cancEdge(key1,key2)
- sizeV()
- sizeE()
- existEdge(key1,key2) --->>> searchEdge(key1,key2)
- findNode(key) --->>> searchNode(key1)
- adjSet(key)
- bfs(key)
- shortestPath(s,t)
- printShortestPath(s,t)
- raggiungibili(key)
- dfs()
- topologicalSort()
- inverti()
- root(j)
- printCC()
- printCC2()
- connectedComponents()

- reset()   - \
- hasNext() --  ITERATORE
- next()    - /


Questi sono i metodi visti a lezione.


Qui,invece,sono riportati i metodi creati da me : 

V -> testati e funzionanti
X -> Non Funzionanti e/o in fase di elaborazione/testing

- stampaCollegamento(key1,key2,out)  V
- archiEntranti(key)  V
- archiUscenti(key)  V
- totArchi(key)  V
- stampaUscenti(key,out)  V
- stampaEntranti(key,out)  V
- stampaTotArchi(key,out)  V
- stampa(out)  V
- stampaArchi(out)  V 
- cycleTest() V

*/
#include <iostream>
#include<string>

#include "Queue.cpp"

#define MAXN 20
#define WHITE 0
#define BLACK 1
#define GRAY 2


using namespace std;

template <class T> class Grafo{
private:
	int n;
	int m;
	int current;
	bool** adj;
	T** k;
	int *d;
	int *p;
	int *color;
	int *iv;//inizio visita dfs
	int *fv;//fine visita dfs
	int *ts; //ordinamento topologico ts[i] indica l'i-esimo nodo nell'ordinamento topologico
	int t;
	int ts_pos; // posizione nel topological sort
	int bfsSource;
	
	int _searchNode(T key){
		for(int i = 0 ; i < n ; i++){
			if(*k[i] == key) return i;
		}
		return -1;
	}
	
	void _bfs(int s){
		if(bfsSource == s) return ;
		//inizializzazione vettori per il calcolo
		for (int i=0; i<n ; i++){
			p[i] = -1;
			color[i]  = WHITE;
			d[i] = -1;
		}
		Queue<int> *q = new Queue<int>(n);
		d[s] = 0;
		color[s] = BLACK;
		q->enqueue(s);
		while(!q->isEmpty()){
			int* i = q->dequeue();
			for(int j=0; j<n ; j++){
				if(adj[*i][j]== 1 && color[j]== WHITE){
					p[j] = *i;
					color[j] = BLACK;
					d[j] = d[*i]+1;
					q->enqueue(j);
				}
			}	
		}
		bfsSource = s;			
	}
	
	void _printBFS(int s){
		if(bfsSource == s) return ;
		//inizializzazione vettori per il calcolo
		for (int i=0; i<n ; i++){
			p[i] = -1;
			color[i]  = WHITE;
			d[i] = -1;
		}
		Queue<int> *q = new Queue<int>(n);
		d[s] = 0;
		color[s] = BLACK;
		q->enqueue(s);
		cout << s << " ";
		while(!q->isEmpty()){
			int* i = q->dequeue();
			for(int j=0; j<n ; j++){
				if(adj[*i][j]== 1 && color[j]== WHITE){
					p[j] = *i;
					color[j] = BLACK;
					d[j] = d[*i]+1;
					q->enqueue(j);
					cout << j << " ";
				}
			}	
		}
		bfsSource = s;			
	}
	
	void _printShortestPath(int j) {
        if(p[j]==-1) {
            cout << *k[j] << " ";
            return;
        }
        _printShortestPath(p[j]);
        cout << *k[j] << " ";
    }
    
    void _dfsVisit(int s){
    	iv[s] = t++;
    	color[s] = GRAY;
    	cout << "Inizio visita DFS(" << s <<") al tempo "<< iv[s] << endl;
    	for(int i = 0;i<n;i++){
    		if(adj[s][i]==1 && color[i]==WHITE){
    			p[i] = s; 
    		 	_dfsVisit(i);
    		}
    	}
    	fv[s] = t++;
    	color[s] = BLACK;
    	cout << "Fine visita DFS(" << s <<") al tempo "<< fv[s] << endl;    	
    }
    
   int _cycleTest(int s){
    	iv[s] = t++;
    	int cycle = 0;
    	color[s] = GRAY;
    	for(int i = 0;i<n;i++){
    		if(adj[s][i]==1){
    			if(color[i] == GRAY){
    				//ciclo presente : cycle posta a true (1)
    				cycle += 1;
    			}
    			if(color[i]==WHITE){
    				p[i] = s; 
    		 		cycle = cycle + _cycleTest(i);
    			}
    		}    	
    	}
    	fv[s] = t++;
    	color[s] = BLACK;
    	return cycle;
    }
    
    int _tps(int s){
    	iv[s] = t++;
    	int cycle = 0;
    	color[s] = GRAY;
    	for(int i = 0;i<n;i++){
    		if(adj[s][i]==1){
    			if(color[i] == GRAY){
    				//ciclo presente 
    				cycle += 1;
    			}
    			if(color[i]==WHITE){
    				p[i] = s; 
    		 		cycle = cycle + _tps(i);
    			}
    		}    	
    	}
    	fv[s] = t++;
    	ts[ts_pos--] = s;
    	color[s] = BLACK;
    	return cycle;
    }	
		
	

public:
	Grafo(){
		n = m = 0;
		adj = new bool*[MAXN];
		for(int i = 0; i < MAXN; i++){
			adj[i] = new bool[MAXN];
		}
		k = new T*[MAXN];
		for(int i = 0; i < MAXN ; i++){
			k[i] = NULL;
		}
		d = new int[MAXN];
		p = new int[MAXN];
		color = new int[MAXN];
		iv = new int[MAXN];
		fv = new int[MAXN];
		ts = new int[MAXN];
		bfsSource = -1;
	}
	
	Grafo<T>& addNode(T key){
		k[n] = new T(key);	
		n++;
		for(int i = 0; i < n ; i++) adj[n][i] = adj[i][n] = 0;
		return *this;	
	}
	
	Grafo<T>& cancNode(T key){
		int i = _searchNode(key);
        	if(i<0) return *this;
        	// sistemo l'array k
       	 k[i] = k[n-1];
        	// sistemo la matrice adj
        	for(int j=0; j<n; j++) {
          	  adj[i][j] = adj[n-1][j];
            	adj[j][i] = adj[j][n-1];
        	}
       	n--;
        	return *this;
	}
	
	Grafo<T>& addEdge(T key1, T key2){
		int i = _searchNode(key1);
		int j = _searchNode(key2);
		if(i<0 || j<0) return *this;
		adj[i][j] = 1;
		//grafo non direzionato
		//adj[j][i] = 1;
		m++;
		return *this;
	}
	
	Grafo<T>& cancEdge(T key1, T key2){
		int i = _searchNode(key1);
		int j = _searchNode(key2);
		if(i<0 || j<0) return *this;
		adj[i][j] = 0;
		//grafo non direzionato
		//adj[j][i] = 0;
		m--;
		return *this;
	}
	
	int searchNode(T key){
		return _searchNode(key);
	}
	
	int searchEdge(T key1,T key2){
		int i = _searchNode(key1);
		int j = _searchNode(key2);
		if(i<0 || j<0) return 0;
		if(adj[i][j] == 1) return 1;
		else return 0;
	}
	
	void stampaCollegamento(T key1,T key2,ostream& out){
		int i = _searchNode(key1);
		int j = _searchNode(key2);
		if(i<0 || j<0) return;
		if(adj[i][j] == 1) out << *k[i] << "->" << *k[j] << endl;
	}


	int sizeV(){
		return n;
	}
	
	int sizeE(){
		return m;
	}
	
	int archiUscenti(T key){
		int i = _searchNode(key);
		if(i<0) return 0;
		int a = 0;
		for(int j=0; j < n ; j++){
			if(adj[i][j] == 1) a++;
		}
		return a ;
	}
	
	int archiEntranti(T key){
		int i = _searchNode(key);
		if(i<0) return 0;
		int a = 0;
		for(int j=0 ; j<n;j++){
			if(adj[j][i] == 1) a++;	
		}
		return a;
	}
	
	int totArchi(T key){
		int a = archiEntranti(key);
		int b = archiUscenti(key);
		int c = a+b;
		return c;
	}
	
	void stampaUscenti(T key,ostream& out){
		int i = _searchNode(key);
		if(i<0) return ;
		for(int j=0; j < n ; j++){
			if(adj[i][j] == 1) out << *k[i] << "->" << *k[j] << endl;
		}
	}
	
	void stampaEntranti(T key,ostream& out){
		int i = _searchNode(key);
		if(i<0) return;
		for(int j = 0; j < n ; j++){
			if(adj[j][i] == 1) out << *k[j] << "->" << *k[i] << endl;
		}
	}
	
	void stampaTotArchi(T key,ostream& out){
		int i = _searchNode(key);
		if(i<0) return;
		stampaUscenti(key,out);
		stampaEntranti(key,out);	
	}
	
	void adjSet(T key, ostream& out){
		int i  =_searchNode(key);
		if(i<0) return;
		for(int j = 0 ; j < n ; j++){
			if(adj[i][j] == 1 ) out << *k[j] << " " ;
		}
		out << endl;
	}
	
	void bfs(T key){
		int s = _searchNode(key);
		if(s<0) return;
		_bfs(s);
	}
	
	void printBFS(T key){
		int s = _searchNode(key);
		if(s<0) return;
		_printBFS(s);
	}
	
	int shortestPath(T source , T target){
		int s = _searchNode(source);
		int t = _searchNode(target);
		if(s<0 || t<0) return -1;
		_bfs(s);
		return d[t];
	}
	
	void printShortestPath(T source,T target){
		int sp = shortestPath(source,target);
		if(sp<0) return;
		cout << "il cammino minimo da "<< source << " a " << target << " e' di " << sp << " unita' :" <<endl;
		int s = _searchNode(source);
		int t = _searchNode(target);
		_printShortestPath(t);
		cout << endl;   	
	}
	
	int raggiungibili(T key){
		int s = _searchNode(key);
		if(s<0) return-1;
		int counter = 0;
		_bfs(s);
		for(int i = 0; i < n ; i++){
			if(d[i]>=0) counter++;
		}
		return counter;
	}
	
	void printRaggiungibili(T key){
		int s = _searchNode(key);
		if(s<0) return;
		int a = raggiungibili(key);
		cout <<"I nodi raggiungibili dal nodo "<< key << " sono " << a << ": ";
		for(int i = 0; i < n ; i++){
			if(d[i]>=0) cout << *k[i] << " ";
		}
		cout << endl;

	}
	
	void dfs(){
		//inizializzazione dei vettori
		for(int i = 0; i < n ; i++){
			p[i] = -1;
			color[i] = WHITE;
			iv[i] = -1;
			fv[i] = -1;
		}
		t = 0;//tempo di visita posto a 0 : inizio la visita
		for(int s=0; s<n;s++){
			if(color[s] == WHITE) _dfsVisit(s);
		}
	}
	
	void dfs_ts(){// dfs che processa i nodi sulla base dei tempi di fine visita (tempi di fine visita)
		//inizializzazione dei vettori
		int ord[n];
		for(int i = 0; i < n ; i++) ord[i] = ts[i];
		for(int i = 0; i < n ; i++){
			p[i] = -1;
			color[i] = WHITE;
			iv[i] = -1;
			fv[i] = -1;
		}
		ts_pos = n-1;
		t = 0;//tempo di visita posto a 0 : inizio la visita
		int cc = 0;
		for(int i = 0; i<n;i++){
			int s = ord[i];
			if(color[s] == WHITE) {
				cc++;
				_tps(s);
			}
		}
		cout << "Nel grafo sono presenti " << cc << " componente fortemente connesse"<< endl;
	}
	
	int cycleTest(){
		// inizializzo i vettori
		for(int i = 0; i < n ; i++){
			p[i] = -1;
			color[i] = WHITE;
			iv[i] = -1;
			fv[i] = -1;
		}
		t = 0;
		int cycle = 0;	
		for(int s=0; s<n;s++){
			if(color[s] == WHITE) cycle = cycle + _cycleTest(s);
			
		}
		return cycle;	
	}
	
	
	int tps(){
		// inizializzo i vettori
		for(int i = 0; i < n ; i++){
			p[i] = -1;
			color[i] = WHITE;
			iv[i] = -1;
			fv[i] = -1;
		}
		ts_pos = n-1;
		t = 0;
		int cycle = 0;	
		for(int s=0; s<n;s++){
			if(color[s] == WHITE) cycle = cycle + _tps(s);
			
		}
		return cycle;	
	}
	
	int topologicalSort(){
		if(tps()!=0){
			cout << "Non esiste un ordinamento topologico" << endl;
			return 1;
		}
		else{
			cout << "< ";
			for(int i = 0; i < n ; i++){
				cout << *k[ts[i]] << " ";
			}
			cout << ">" << endl;
		}
		return 0;
	}
	
	void trasponi() {
        	for(int i=0; i<n; i++) {
       		for(int j=i+1; j<n; j++) {
       			if(adj[i][j]!=adj[j][i]) {
        	        		int tmp = adj[i][j];
        	            		adj[i][j] = adj[j][i];
        	            		adj[j][i] = tmp;
        	        	}
            	}
        }
    }
	
	void printCC() {
        	// le radici degli alberi DFS sono i nodi per cui p[i]=-1
        	int cc = 0;
        	for(int i=0; i<n; i++) if(p[i]==-1) { // analizzo tutte le radici della foresta DFS
        	    cout << "{ ";
        	    cc++;
        	    for(int j=0; j<n; j++)
        	        if(root(j)==i)  // oppure chiamare root(j)
        	            cout << *k[j] << " ";
        	    cout << "} ";
        	}
        	cout << endl;
       }		 
	
	int connectedComponents(){
		//1. prima DFS utilizzando l'ordine standard(in realtà non è importante l'ordine,l'importante è il calcolo di fv)
		tps();
		//2. costruiamo il grafo trasposto (si inverte l'ordine degli archi)
		trasponi();
		//3. seconda DFS utilizzando suggerito dai tempi di fine visita
		dfs_ts();
		//4. restituire ogni albero DFS come una diversa componente connessa
		trasponi();
		printCC();
		return 0;
	}
	
	//restituisce la radice dell'albero DFS che contiene il nodo j
	int root(int j){
		while(p[j]!=-1){
			j = p[j];
		}
		return j;
	}
	   
    // iteratore
    void reset() {
        current = 0;
    }
    int hasNext() {
        return current<n;
    }
    T* next() {
        if(!hasNext()) return NULL;
        T* tmp = k[current];
        current++;
        return tmp;
    }

};



template <class T> ostream& operator<<(ostream& out, const Grafo<T>& g) {
    Grafo<T> tmp = g;
    tmp.reset();
    int id = 0;
    while(tmp.hasNext()) {
        T* e = tmp.next();
        out << "(" << id << "," << *e << ") --> ";
        id++;
        tmp.adjSet(*e, out);
        out << endl;
    }
    return out;
}

