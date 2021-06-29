#include <iostream>
#include <fstream>
#include "Queue.cpp"
using namespace std;

#define MAXN 20
#define WHITE 0
#define BLACK 1
#define GRAY 2

//rappresentazione del grafo attraverso la matrice di adiacenza
template <class T> class Graph {
private:
    bool **adj; //adj[MAXN][MAXN];
    int n, m, current;
    T** k; // k[i] -> key se i è l'id della chiave key
    int *p; // vettore dei parent
    int *color; // vettore dei colori
    int *d; // vettore delle distanze
    int *iv,*fv; // inizio e fine visita dfs
    int *ts;  //ordinamento topologico
    int *r; // vettore delle radici della foresta DFS r[j]=i se j appartiene all'albero DFS di i
    int ts_pos; // posizione nel topological sort
    int t;
    int bfsSource; // informazione sulla sorgente relativa all'ultima chiamata BFS
    int _search(T key) {
        for(int i=0; i<n; i++) {
            if( *k[i] == key ) return i;
        }
        return -1;
    }
    
    void _bfs(int s) {      // O(n^2) (Matrici) - O(n+m) (Liste)
        //inizializzazione dei vettori
        if(bfsSource==s) return;
        //cout << "bfs(" << s << ")" << endl;
        for(int i=0; i<n; i++) {            // O(n)
            p[i] = -1;
            color[i] = WHITE;
            d[i] = -1;
        }
        Queue<int> *q = new Queue<int>(n);
        d[s] = 0;
        color[s] = BLACK;
        q->enqueue(s);
        while(!q->isEmpty()) {       // O(n)
            int* i = q->dequeue();   // ogni nodo viene estratto solo una volta (al più)
            for(int j=0; j<n; j++) {    // O(n)
                if(adj[*i][j]==1 && color[j]==WHITE) {
                    p[j] = *i;
                    color[j] = BLACK;
                    d[j] = d[*i]+1;
                    q->enqueue(j);
                }
            }
        }
        bfsSource = s;
    }
    
    void _printShortestPath(int i, int j) {
        if(i==j) {
            cout << i << " ";
            return;
        }
        _printShortestPath(i, p[j]);
        cout << j << " ";
    }

    void _printShortestPath(int j) {
        if(p[j]==-1) {
            cout << j << " ";
            return;
        }
        _printShortestPath(p[j]);
        cout << j << " ";
    }

    int _dfsVisit(int s) {
        iv[s] = t++;
        int cycle = 0;
        color[s] = GRAY;
        //cout << "Inizio visita nodo " << s << " al tempo "<< iv[s]<<endl;
        for(int i=0; i<n; i++)
            if(adj[s][i]==1) {
                if(color[i]==BLACK) {
                    // si tratta di un arco di attraversamento o in avanti
                    //if(iv[s]<fv[i])
                    //    cout << "(" << s << "," << i << ") è un arco in avanti" << endl;
                    //else cout << "(" << s << "," << i << ") è un arco di attraversamento" << endl;
                }
                if(color[i]==GRAY) {
                    // abbiamo trovato un ciclo
                    //cout << "(" << s << "," << i << ") è un arco all'indietro" << endl;
                    cycle += 1;
                }
                if(color[i]==WHITE) {
                    //cout << "(" << s << "," << i << ") è un arco dell'albero" << endl;
                    p[i] = s;
                    r[i] = r[s];
                    cycle = cycle + _dfsVisit(i);
                }
            }
        fv[s] = t++;
        ts[ts_pos--] = s;
        //cout << "Fine visita nodo " << s << " al tempo " << fv[s] << endl;
        color[s] = BLACK;
        return cycle;
    }
    
public:
    Graph() {
        n = m = 0;
        adj = new bool*[MAXN];
        for(int i=0; i<MAXN; i++)
            adj[i] = new bool[MAXN];
        k = new T*[MAXN];
        for(int i=0; i<MAXN; i++) k[i] = NULL;
        current = 0;
        p = new int[MAXN];
        color = new int[MAXN];
        d = new int[MAXN];
        r = new int[MAXN];
        iv = new int[MAXN];
        fv = new int[MAXN];
        ts = new int[MAXN];
        bfsSource = -1;
    }
    
    Graph<T>& addNode(T key) {
        // inseriamo il nodo all'interno dell'array k
        k[n] = new T(key);
        n++;
        // aggiorniamo la matrice di adiacenza
        for(int i=0; i<n; i++) adj[n][i] = adj[i][n] = 0;
        return *this;
    }

    Graph<T>& cancNode(T key) {
        int i = _search(key);
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

    Graph<T>& addEdge(T key1, T key2) {
        int i = _search(key1);
        int j = _search(key2);
        if(i<0 || j<0) return *this;
        adj[i][j] = 1;
        // se il grafo fosse non direzionato:
        // adj[j][i] = 1;
        m++;
        return *this;
    }

    Graph<T>& cancEdge(T key1, T key2) {
        int i = _search(key1);
        int j = _search(key2);
        if(i<0 || j<0) return *this;
        adj[i][j] = 0;
        // se il grafo fosse non direzionato:
        // adj[j][i] = 0;
        m--;
        return *this;
    }

    int sizeV() {
        return n;
    }
    
    int sizeE() {
        return m;
    }
    
    int existEdge(T key1, T key2) {
        int i = _search(key1);
        int j = _search(key2);
        if(i<0 || j<0) return 0;
        return adj[i][j];
    }
    
    int findNode(T key) {
        int i = _search(key);
        return i;
    }
    
    void adjSet(T key, ostream& out) {
        int i = _search(key);
        if(i<0) return;
        out << "{ ";
        for(int j=0; j<n; j++) {
            if(adj[i][j]==1)
                out << *k[j] << " ";
        }
        out << "}";
    }
    
    void bfs(T key) {
        int s = _search(key);
        if(s<0) return;
        //inizializzazione dei vettori
        _bfs(s);
    }
    
    int shortestPath(T source, T target) {
        int s = _search(source);
        int t = _search(target);
        if(s<0 || t<0) return -1;
        _bfs(s);
        return d[t];
    }

    void printShortestPath(T source, T target) {
        int sp = shortestPath(source, target);
        if(sp>=0) {
            cout << "(" << sp << ") ";
            int t = _search(target);
            _printShortestPath(t);
            cout << endl;
        }
    }

    void raggiungibili(T key) {
        int s = _search(key);
        cout << "{ ";
        if(s>=0) {
            _bfs(s);
            for(int i=0; i<n; i++)
                if(d[i]>=0) cout << *k[i] << " ";
        }
        cout << "}" << endl;
    }
    
    int dfs(int par=0) { // restituisce 1 se il grafo presenta dei cicli
        //inizializzazione dei vettori
        int ord[n];
        for(int i=0; i<n; i++) ord[i] = ts[i];
        for(int i=0; i<n; i++) {            // O(n)
            p[i] = -1;
            color[i] = WHITE;
            iv[i] = fv[i] = -1;
            r[i] = -1;
        }
        ts_pos = n-1;
        t = 0; // tempo di visita posto a 0
        int cycle = 0;
        for(int i=0; i<n; i++) {
            int s = i;
            if(par==1) s = ord[i];
            if(color[s]==WHITE) {
                r[s] = s;
                cycle = cycle + _dfsVisit(s);
            }
        }
        return cycle;
    }
    
    
    int topologicalSort() {
        if(dfs()) {
            cout <<  "Non esiste un ordinamento topologico del grafo" << endl;
            return 1;
        }
        cout << "< ";
        for(int i=0; i<n; i++)
            cout << ts[i] << " ";
        cout << ">" << endl;
        return 0;
    }

    void inverti() {
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
/*
     0 1 2 3

 0   0 1 1 0
 1   0 0 0 1
 2   1 0 0 0
 3   0 0 0 0
 */
    
    // restituisce la radice dell'albero DFS che contiene il nodo j
    int root(int j) {
        while(p[j]!=-1)
            j = p[j];
        return j;
    }

    void printCC2() {
        // le radici degli alberi DFS sono i nodi per cui p[i]=-1
        int cc = 0;
        int processed[MAXN] = {0}; // processed[i]=1 se ho già stampato la cc di i
        for(int i=0; i<n; i++) if(!processed[i]) {
            cout << "{ " << i << " ";
            cc++;
            for(int j=i+1; j<n; j++)
                if(r[j]==r[i])  {
                    cout << j << " ";
                    processed[j] = 1;
                }
            cout << "} ";
        }
        cout << endl;
        cout << "Nel grafo sono presenti " << cc << " componenti fortemente connesse"<< endl;
    }
    
    void printCC() {
        // le radici degli alberi DFS sono i nodi per cui p[i]=-1
        int cc = 0;
        for(int i=0; i<n; i++) if(p[i]==-1) { // analizzo tutte le radici della foresta DFS
            cout << "{ ";
            cc++;
            for(int j=0; j<n; j++)
                if(r[j]==i)  // oppure chiamare root(j)
                    cout << j << " ";
            cout << "} ";
        }
        cout << endl;
        cout << "Nel grafo sono presenti " << cc << " conponenti fortemente connesse"<< endl;
    }
    
    int connectedComponents() {
        // 1. prima DFS utilizzando l'ordine standard per calcolare i tempi di fine visita
        dfs();
        // 2. costruiamo il grafo con gli archi invertiti
        inverti();
        // 3. seconda DFS utilizzando l'ordine suggerito dai tempi di fne visita
        dfs(1); // chiamata con parametro 1
        // 4. restitutire ogni albero DFS come una diversa Componente Connessa
        printCC2();
        inverti();
        return 0;
    }
    
    int archiIndietro(){
    	for(int i=0; i<n; i++) {            // O(n)
            p[i] = -1;
            color[i] = WHITE;
            iv[i] = fv[i] = -1;
            r[i] = -1;
        }
        int cycle;
        return _dfsVisit(cycle);
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

template <class H> ostream& operator<<(ostream& out, const Graph<H>& g) {
    Graph<H> tmp = g;
    tmp.reset();
    int id = 0;
    while(tmp.hasNext()) {
        H* e = tmp.next();
        out << "(" << id << "," << *e << ") --> ";
        id++;
        tmp.adjSet(*e, out);
        out << endl;
    }
    return out;
}


int main() {
    Graph<int> *g = new Graph<int>();
    for(int i=0; i<=7; i++)
        g->addNode(i);
    //g->addEdge(0,1).addEdge(0,4);
    g->addEdge(1,5).addEdge(1,2).addEdge(1,0);
    g->addEdge(2,1);
    g->addEdge(3,5).addEdge(3,7);
    g->addEdge(4,2).addEdge(4,6);
    g->addEdge(5,6).addEdge(5,3);
    g->addEdge(6,7).addEdge(6,5);
    //g->addEdge(7,5).addEdge(7,6);
    
    //archi da inserire per avere una sola CC
    //g->addEdge(0,4);
    //g->addEdge(7,4);
    
    cout << *g << endl;
    g->connectedComponents();
}

// 1 -> 2 -> 3 -> 4 -> 5

/*
(0 .. (1 .. (3 .. 3) 1) (2 .. (5 .. (6 .. 6) 5) 2) (4 .. (7 .. 7) 4) 0)

        0
    1   2  4
    3   5  7
        6

possibili relazioni tra la visita di x e di y:
(x .. (y .. y) x) --> y è discendente di x
(y .. (x .. x) y) --> x è discendente di y
(x .. x) (y .. y) --> x e y non hanno alcuna relazione
(y .. y) (x .. x) --> x e y non hanno alcuna relazione

(x .. (y .. x) y) --> impossibile
(y .. (x .. y) x) --> impossibile
*/

/*
( ....  (x ...  (y ..      )        )

x--> --> --> -->y --> x
*/

/*
 (s .. ( i .. )        )   -> arco in avanti   iv[s]<fv[i]
                    ^
                  s-->i
 
 ( i .. ) (s ..        )   -> arco di attraversamento  iv[s]>fv[i]
                    ^
                  s-->i

 
*/


// 1 3 5 6 0 2 4 7
// 0 2 1 3 5 6 4 7
// 2 0 1 3 5 4 6 7

// 0 1 2 3 4 5 6 7

// quanti ordinamenti possono esistere (n nodi)?:
// n!
//
// n + nlogn + n( L * n) = n + nlogn + mn =
// O(nm+nlogn)
//
/* (0(4(7) ) ) (1(3 ) (5 (6 )  )  )  (2  )
 1 2 3 4 5 6 7 8  9 10 11 12 13 14 15 16

0: 1  6
1: 7  14
2: 15 16
3: 8  9
4: 2  5
5: 10 13
6: 11 12
7: 3  4

2 1 5 6 3 0 4 7
*/
/*
(0 (2 (1 ) (4 (7 (6 (5 (3 )  )  )  )  )  )  )
1  2  3  4 5  6  7  8  9  10 11 12 13 14 15 16

0: 1  16
1: 3  4
2: 2  15
3: 9  10
4: 5  14
5: 8  11
6: 7  12
7: 6  13

0 2 4 7 6 5 3 1
*/

