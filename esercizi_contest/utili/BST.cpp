#include <iostream>
#include "list.cpp"
/*
Altezza di un nodo - Numero di spigoli sul percorso più lungo da quel nodo alla foglia più lontana.

Profondità: numero di spigoli sul percorso da quel nodo alla radice.

L'altezza dell'albero è, Altezza della radice.

La profondità dell'albero è, la profondità massima nell'albero.
*/
using namespace std;

template <class T> class Nodo{
private:
	T *key;
	Nodo<T> *left, *right, *parent;
	
public:
	Nodo(T key){
		this->key  = new T(key);
		left = NULL;
		right = NULL; 
		parent = NULL;
	}
	
	// metodi get
	
	T getKey(){
		return *key;
	}
	
	Nodo<T>* getRight(){
		return right;
	}
	
	Nodo<T>* getLeft(){
		return left;
	}
	
	Nodo<T>* getParent(){
		return parent;
	}
	
	// metodi set
	
	void setKey(T key){
		*(this->key) = key;
	}
	
	void setRight(Nodo<T>* right){
		this->right = right;
	}
	
	void setLeft(Nodo<T>* left){
		this->left = left;
	}
	
	void setParent(Nodo<T>* parent){
		this->parent = parent;
	}
};

template <class T> class BST{
private:
	Nodo<T>* root;
	int n;
	List<T> *d;
	
	Nodo<T>* _search(T key,Nodo<T>* x){
		if(!x) return NULL;
		if( key == x->getKey()) return x;
		if(key < x->getKey()) return _search(key,x->getLeft()); 
		else return _search(key, x->getRight());		
	}
	
	Nodo<T>* _max(Nodo<T>* x){
		if(!x) return NULL;
		if(!x->getRight()) return x;
		else return _max(x->getRight());
	}
	
	Nodo<T>* _min(Nodo<T>* x){
		if(!x) return NULL;
		if(!x->getLeft()) return x;
		else return _min(x->getLeft());
	}
	
	Nodo<T>* _successore(Nodo<T>* x){
		if(!x) return NULL;
		if(x->getRight()) return _min(x->getRight());
		Nodo<T>* tmp = x;
		while(tmp && tmp->getKey() <= x->getKey()) tmp = tmp->getParent();
		return tmp;
	}
	
	Nodo<T>* _predecessore(Nodo<T>* x){
		if(!x) return NULL;
		if(x->getLeft()) return _max(x->getLeft());
		Nodo<T> *tmp = x;
		while(tmp && tmp->getKey() >= x->getKey()) tmp = tmp->getParent();
		return tmp;
	}
	
	void _preorder(Nodo<T>* x, ostream& out){
		if(!x) return;
		out << x->getKey() << " " ;
		_preorder(x->getLeft(),out);
		_preorder(x->getRight(), out);
	}
	
	void _inorder(Nodo<T>* x, ostream& out){
		if(!x) return;
		_inorder(x->getLeft(),out);
		out << x->getKey() << " " ;
		_inorder(x->getRight(), out);
	}
	
	void _postorder(Nodo<T>* x, ostream& out){
		if(!x) return;
		_postorder(x->getLeft(),out);
		_postorder(x->getRight(), out);
		out << x->getKey() << " " ;
	}
	
	int _FBP(Nodo<T>* x){
		Nodo<T>* tmp = _min(x);
		if(tmp == x) return 0;
		int diff=0;
		int s=0;
		int d=0;
		while(tmp && tmp->getKey() < x->getKey()){
			tmp = _successore(tmp);
			s++;
		}
		Nodo<T>* tmp1 = _max(x);
		while(tmp1 && tmp1->getKey() > x->getKey()){
			tmp1 = _predecessore(tmp1);
			d++;
		}
		diff = abs(d-s);
		return diff;
	}
	
	int _leafcount(Nodo<T> *x){
		if(!x) return 0;
		if(!x->getLeft() && !x->getRight()) return 1;
		return _leafcount(x->getLeft()) + _leafcount (x->getRight()); 
	}
	
	int _nodeCount(Nodo<T>* x) {
        if(!x) return 0;
        return 1+_nodeCount(x->getLeft())+_nodeCount(x->getRight());
    }
    
    void _printLeaves(Nodo<T>* x){
		if(!x) return ;
		if(!x->getRight() && !x->getLeft()){
			cout << x->getKey() << " ";
			return;
		}
		if(x->getLeft()) _printLeaves(x->getLeft());
		if(x->getRight()) _printLeaves(x->getRight());	
	}
	
	//funzione ricorsiva che calcola la profondità di un nodo contenente la chiave key nel sottoalbero radicato in x
	int _rprof(T key,Nodo<T>* x){
		if(x==NULL) return -1;
		if(x->getKey() == key) return 0;
		int p;
		if(key < x->getKey()) return p =_rprof(key,x->getLeft());
		else return p =_rprof(key,x->getRight());
		if(p>0) return p+1;
		else return -1;
	}
	//funzione iterativa che calcola la profondità di un nodo contenente la chiave key nel sottoalbero radicato in x
	int _prof(T key,Nodo<T>* x){
		if(!x) return -1;
		Nodo<T> *tmp = x;
		int p=0;
		while(tmp && tmp->getKey()!=key){
			if(key < tmp->getKey()) tmp = tmp->getLeft();
			else tmp = tmp->getRight();
			p++;			
		}
		if(!tmp) return -1;
		else return p;
	}
	//funzione iterativa che calcola l'altezza di un nodo contenente la chiave key nel sottoalbero radicato in x
	int _altezza(Nodo<T>* x){
		Nodo<T>* tmp = _min(x);
		int p=0;
		while(tmp!=NULL){//O(n)
			int t = _prof(tmp->getKey(),x);
			if(t>p) p = t;
			tmp = _successore(tmp);//O(n)
		}
		return p;
	
	}
	
	void _merge(T *v, int n , int m){
		T b[n];
		int i,j,k;
		i = k = 0;
		j = m;
		while(i<m && j<n){
			if(v[i]<v[j]) b[k++]=v[i++];
			else b[k++]=v[j++];	
		}
		while(i<m) b[k++]=v[i++];
		while(j<n) b[k++]=v[j++];
		for(int i=0;i<n;i++) v[i]=b[i];
	}
	
	void _mergesort(T *v,int n){
    		if(n<=1) return;	
		int m = n/2;
		//v[0 . . m-1] +v[m . . n-1]
		_mergesort(v,m);
		_mergesort(v+m,n-m);
		_merge(v,n,m);
   	 }
	
public:
	BST(){
		root = NULL;
		n = 0;
		d = new List<T>();
	}
	
	
	BST<T>& ins(T key){
		Nodo<T>* x = new Nodo<T>(key);
		Nodo<T>* parent = NULL;
		Nodo<T>* tmp = root;
		n++; 
		while(tmp){
			parent = tmp;
			if(key < tmp->getKey()) tmp = tmp->getLeft();
			else tmp = tmp->getRight();
		}
		if(!parent) root = x;
		else {
			if(parent->getKey() < key) parent->setRight(x);
			else parent->setLeft(x);
			x->setParent(parent);
		}
		return *this;
	}
	
	BST<T>& canc(T key){
		Nodo<T>* x = _search(key,root);
		if(!x) return *this;
		//caso 3
		if(x->getLeft() && x->getRight()){
			Nodo<T>* s = _successore(x);
			s->setParent(x->getParent());
			x->setKey(s->getKey());
			s->setKey(key);
			x = s;
		}
		//casi 1 e 2
		Nodo<T>* p = x->getParent();
		Nodo<T>* y = x->getLeft();
		if(!y) y = x->getRight();
		if(!p) root = y;
		else{
			if(key < p->getKey()) p->setLeft(y);
			else p->setRight(y);
		}
		if(y) y->setParent(p);
		n--;
		return *this;
	}
	
	int search(T key){
		return(_search(key,root)!=NULL);
	}
	
	int size(){
		return n;
	}
	
	int isEmpty(){
		return (n == 0);
	}
	
	T max(){
		Nodo<T>* tmp = _max(root);
		if(tmp) return tmp->getKey();
		else return NULL;
	}
	
	T min(){
		Nodo<T>* tmp = _min(root);
		if(tmp) return tmp->getKey();
		else return NULL;
	}
	
	T successore(T key){
		Nodo<T> *x = _search(key,root);
		if(x){
			Nodo<T>* tmp = _successore(x);
			if(tmp) return tmp->getKey();
			else return NULL;
		}
		return NULL;
	}
	
	T predecessore(T key){
		Nodo<T> *x = _search(key,root);
		if(x){
			Nodo<T>* tmp = _predecessore(x);
			if(tmp) return tmp->getKey();
			else return NULL;
		}
		return NULL;
	}
	
	void preorder(ostream& out){
		_preorder(root,out);
	}
	
	void inorder(ostream& out){
		_inorder(root,out);
	}
	
	void postorder(ostream& out){
		_postorder(root,out);
	}
		
	bool isBalanced(){// restituisce true se l'albero è bilanciato in peso
		Nodo<T>* tmp = _min(root);
		for(int i=0; i<n ; i++){
			if(!tmp->getRight() && !tmp->getLeft()) tmp = _successore(tmp);	
			else{
				if(_FBP(tmp) ==1 || _FBP(tmp) == 0)
					tmp = _successore(tmp);
				else return false;	
			}
		}
		return true; 
	}
	
	T commonAncestor(T key1 , T key2){
		Nodo<T>* x = root;
        	T k1 = key1<key2?key1:key2;
        	T k2 = key1>=key2?key1:key2;
        	//if(key1>=key2){
        	//	 k1 = key1;
        	//	 k2 = k2;
        	//}
        	while(!(k1<=x->getKey() && k2>=x->getKey())) {
           	 if(k1<x->getKey()) x=x->getLeft();
           	 else  x=x->getRight();
        	}
        	return x->getKey();
	}
	
	int countRange(T key1, T key2){
		int k=1;
		T k1 = key1<key2?key1:key2;
        	T k2 = key1>=key2?key1:key2;
		Nodo<T> *x = _search(k1,root);
		Nodo<T> *y = _search(k2,root);
		if(x && y){
			while(x!=y){
				x = _successore(x);
				k++;
			}
		}
		return k+2;
	}
	
	List<T>& listKey(){
		Nodo<T> *tmp = _min(root);
		while(tmp){
			d->insert(tmp->getKey());
			tmp = _successore(tmp);
		}
		return *d;
	}
	
	int oneChild(){
		Nodo<T> *tmp = _min(root);
		int res=0;
		while(tmp){
			if(!(tmp->getRight() && tmp->getLeft()) && (tmp->getRight() || tmp->getLeft()))
				res++;
			tmp = _successore(tmp);
		}
		return res;
		
	}
	
	void printOneChild(ostream& out){
		Nodo<T>* tmp = _min(root);
		while(tmp){
			if(!(tmp->getRight() && tmp->getLeft()) && (tmp->getRight() || tmp->getLeft()))
			out << tmp->getKey() << " ";
			tmp = _successore(tmp);
		}
		out << endl;
	}
	
	int twoChildren(){
		Nodo<T> *tmp = _min(root);
		int res=0;
		while(tmp){
			if(tmp->getRight() && tmp->getLeft()) 
				res++;
			tmp = _successore(tmp);
		}
		return res;
	}
	
	void printTwoChildren(ostream& out){
		Nodo<T> *tmp = _min(root);
		while(tmp){
			if(tmp->getRight() && tmp->getLeft()) 
			out << tmp->getKey() << " ";
			tmp = _successore(tmp);
		}
		out << endl;
	}
	
	int treshold(int k){
		Nodo<T>* tmp =_min(root);
		int res = 0;
		while(tmp->getKey() < k){
			res++;
			tmp= _successore(tmp); 
		}
		return res;
	}
	
	void printTreshold(T k){// se volessimo farlo su output -> ostream& out  ---- out << tmp->getKey()
		Nodo<T>* tmp =_min(root);
		while(tmp->getKey() < k){
			cout << tmp->getKey() << " ";
			tmp= _successore(tmp); 
		}
	}
	
	void secondLargest(){// possiamo passare lo stream se vogliamo mandarlo su file e non a video
		Nodo<T> *x = _max(root);
		Nodo<T> *y = _predecessore(x);
		cout << y->getKey() << endl;
	}
	
	int leafcount(){
		return _leafcount(root);
	}
	void printLeaves(){
		_printLeaves(root);
	}
	
	int bilanciamento(T key) {// equivalente alla _FBP()
        Nodo<T>* x = _search(key, root);
        int nleft = _nodeCount(x->getLeft());
        int nright = _nodeCount(x->getRight());
        int v = nleft-nright;
        if(v<0) v=v*(-1);
        return v;
    }		
    
    //calcola la profondità del nodo che contiene la chiave key
 	int prof(T key){
 		return _prof(key,root);		
 	}
 	// altezza albero
	int altezza(){
		return _altezza(root);
	}
	
	int nodesPerLevel(int k){
		Nodo<T>* tmp = _min(root);
		int res = 0;
		while(tmp){
			if(_prof(tmp->getKey(),root)==k)
				res++;
				tmp = _successore(tmp);
		}
		return res;
	}	
	
	void printlevel(int k){
		Nodo<T>* tmp = _min(root);
		while(tmp){
			if(_prof(tmp->getKey(),root)==k)
			cout << tmp->getKey() << " ";
			tmp = _successore(tmp);
		}
		cout << endl;		
	}
	
	void naturalFill(T *v, int n) {
		_mergesort(v,n);
        	if(n!=this->n) {
        	    cout << "Natural Fill non eseguibile" << endl;
       	     return;
       	 }
       	 int i=0;
      	 	 Nodo<T>* tmp = _min(root);
       	 for(int i=0; i<n; i++) {
           		 Nodo<T>* y = _successore(tmp);
           		 tmp->setKey(v[i]);
           		 tmp = y;
        	}
    	}
    
    
};

template <class T> ostream& operator<<(ostream& out, const BST<T>& tree){
	BST<T> tmp = tree;
	tmp.inorder(out);
	return out;
}

template <class T> ostream& operator<< (ostream& out, const List<T>& list){
	List<T> tmp = list;
	tmp.reset();
	while(tmp.hasNext()){
		out << *(tmp.next()) << " ";
	}
	return out;
}
/*
int main(){
	BST<string> *maria = new BST<string>();
	maria->ins("MARIA").ins("FRANCESCA").ins("SALVATORE").ins("SELENE").ins("PEPPINO").ins("LUCE").ins("AMATO").ins("SONIA").ins("SUSI").ins("PEPPE").ins("MIANO").ins("MOBILIA");
	cout << *maria << endl;
	/*cout << maria->min() << endl;
	cout << maria->max() << endl;
	cout << maria->successore("PEPPE")<<endl;
	cout << maria->predecessore("MARIA") << endl;*/
	/*maria->canc("PEPPE");
	cout << *maria << endl;*/
	/*if(maria->isBalanced() == true) cout << "albero bilanciato" << endl;
	else cout << "albero non bilanciato "<< endl;
	cout << maria->isBalanced() << endl;
	*/
	//cout << " il common ancestor fra MOBILIA e SUSI sara' " << maria->commonAncestor("MOBILIA" , "SUSI")<< endl;
	//cout << "fra LUCE  e PEPPINO  ci sono " << maria->countRange("LUCE", "PEPPINO") << " nodi" << endl; 
	//cout << maria->listKey() << endl;
	/*cout << "i nodi con un solo figlio all'interno dell'albero sono " << maria->oneChild() << " e sono:"<<endl;
	maria->printOneChild(cout); 	
	cout << "i nodi con due figli all'interno dell'albero sono " << maria->twoChildren() <<" e sono:"<< endl;
	maria->printTwoChildren(cout);
	string a = "PEPPINO1";
	maria->printTreshold(a);*/
	//cout << "la seconda chiave più grande presente nell'albero e': ";
	//maria->secondLargest();
	/* cout << "L'albero ha altezza " << maria->altezza() << endl;
	 cout << " al livello zero si trova "<< maria->nodesPerLevel(0) <<  " chiavi  che e' la root ed e' :" << endl;
	 maria->printlevel(0);
	 cout << " al livello uno si trovano "<< maria->nodesPerLevel(1) <<  " chiavi  e sono :" << endl;
	 maria->printlevel(1);
	 cout << " al livello due si trovano "<< maria->nodesPerLevel(2) <<  " chiavi  e sono :" << endl;
	 maria->printlevel(2);
	 cout << " al livello tre si trovano "<< maria->nodesPerLevel(3) <<  " chiavi  e sono :" << endl;
	 maria->printlevel(3);
	 cout << " al livello quattro si trovano "<< maria->nodesPerLevel(4) <<  " chiavi  e sono :" << endl;
	 maria->printlevel(4);
	 cout << " al livello cinque si trovano "<< maria->nodesPerLevel(5) <<  " chiavi  e sono :" << endl;
	 maria->printlevel(5);
	 cout << "ci sono " << maria->leafcount() << " foglie, ed esse sono :" << endl;
	 maria->printLeaves();
	 cout << endl;
	 cout << "APPLICO ORA UN NATURAL FILL INSERENDO ALTRE STRINGHE ALL'INTERNO DELLA STRUTTURA "<< endl;
	 string a[] ={"LUCIA","VINCENZO","MARIA","SAVERIO","DORA","PEPPINO","ROSY","GIANNI","MARIO","SELENE","SOFIA","AGATINO"};
	 cout << " le nuove stringhe sono : "<< endl;
	 for(int i=0; i<maria->size(); i++){
	 	cout << a[i] << " ";
	 }
	 cout << endl;
	 cout << "la procedura ha al suo interno un algoritmo di sorting così che non si debbano scrivere le keys per forza in ordine " << endl;
	 maria->naturalFill(a,maria->size());
	 cout << *maria << endl;
	 cout << "A procedura ultimata otterremo la seguente struttura dati:" << endl;
	 cout << "L'albero ha altezza " << maria->altezza() << endl;
	 cout << " al livello zero si trova "<< maria->nodesPerLevel(0) <<  " chiavi  che e' la root ed e' :" << endl;
	 maria->printlevel(0);
	 cout << " al livello uno si trovano "<< maria->nodesPerLevel(1) <<  " chiavi  e sono :" << endl;
	 maria->printlevel(1);
	 cout << " al livello due si trovano "<< maria->nodesPerLevel(2) <<  " chiavi  e sono :" << endl;
	 maria->printlevel(2);
	 cout << " al livello tre si trovano "<< maria->nodesPerLevel(3) <<  " chiavi  e sono :" << endl;
	 maria->printlevel(3);
	 cout << " al livello quattro si trovano "<< maria->nodesPerLevel(4) <<  " chiavi  e sono :" << endl;
	 maria->printlevel(4);
	 cout << " al livello cinque si trovano "<< maria->nodesPerLevel(5) <<  " chiavi  e sono :" << endl;
	 maria->printlevel(5); 
	 cout << "ci sono " << maria->leafcount() << " foglie, ed esse sono :" << endl;
	 maria->printLeaves();
	 cout << endl;
	 
	 cout << maria->search("PEPPINO")<< endl;
	 cout << maria->max() << endl;		
}

*/
