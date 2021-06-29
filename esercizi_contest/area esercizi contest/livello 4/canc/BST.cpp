#include <iostream>
#include <fstream>
#include"list.cpp"
using namespace std;

// soluzione del problema natural-fill contenuto all'interno del Coding Contest

template <class T> class Nodo {
private:
    T *key;
    Nodo<T> *left, *right, *parent;
public:
    Nodo(T& key) {
        this->key = &key;
        left = right = parent = NULL;
    }
    
    //metodi get
    T& getKey() { return *key;}
    Nodo<T>* getLeft() {return left;}
    Nodo<T>* getRight() {return right;}
    Nodo<T>* getParent() {return parent;}

    //metodi set
    void setKey(T& key) {
        this->key = &key;
    }
    void setLeft(Nodo<T> *left) {
        this->left = left;
    }
    void setRight(Nodo<T> *right) {
        this->right = right;
    }
    void setParent(Nodo<T> *parent) {
        this->parent = parent;
    }

};


template <class T> class BST {
private:
    int n;
    Nodo<T>* root, *current;
    List<T> *d;
    
    Nodo<T>* _search(Nodo<T>* x, T key) {
        if(!x) return NULL;
        if(x->getKey()==key) return x;
        if(key <= x->getKey())
            return _search(x->getLeft(), key);
        else return _search(x->getRight(), key);
    }
    
    Nodo<T>* _imin(Nodo<T>* x){
		if(!x) return NULL;
		Nodo<T> *tmp = x;
		while(tmp->getLeft())	tmp= tmp->getLeft();
		return tmp;
	}
    
    Nodo<T>* _min(Nodo<T>* x) {
        if(!x) return NULL;
        if(!x->getLeft()) return x;
        return _min(x->getLeft());
    }
    
    Nodo<T>* _imax(Nodo<T>* x){
		if(!x) return NULL;
		Nodo<T> *tmp = x;
		while(tmp->getRight())	tmp= tmp->getRight();
		return tmp;
	}
    
    Nodo<T>* _max(Nodo<T>* x){
        if(!x) return NULL;
        if(!x->getRight()) return x;
        return _max(x->getRight());
    }
    
    Nodo<T>* _successore(Nodo<T>* x) {
        if(!x) return NULL;
        if(x->getRight())
            return _min(x->getRight());
        Nodo<T>* p = x->getParent();
        while(p && p->getRight()==x) {
            x = p;
            p = p->getParent();
        }
        return p;
    }
    
    Nodo<T>* _predecessore(Nodo<T>* x) {
        if(!x) return NULL;
        if(x->getLeft())
            return _max(x->getLeft());
        Nodo<T>* p = x->getParent();
        while(p && p->getLeft()==x) {
            x = p;
            p = p->getParent();
        }
        return p;
    }
    
    void _inorder(Nodo<T>* x,ostream& out) {
        if(!x) return;
        _inorder(x->getLeft(),out);
        out << x->getKey() << " ";
        _inorder(x->getRight(),out);
    }
    
    void _preorder(Nodo<T>* x,ostream& out) {
        if(!x) return;
        out << x->getKey() << " ";
        _preorder(x->getLeft(),out);
        _preorder(x->getRight(),out);
    }
    
    void _postorder(Nodo<T>* x,ostream& out){
        if(!x) return;
        _postorder(x->getLeft(),out);
        _postorder(x->getRight(),out);
        out << x->getKey() << " ";
    }
    
    int _leafCount(Nodo<T>* x) {
        if(!x) return 0;
        if(!x->getLeft() && !x->getRight()) return 1;
        return _leafCount(x->getLeft()) + _leafCount(x->getRight());
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
    
    int _nodeCount(Nodo<T>* x) {
        if(!x) return 0;
        return 1+_nodeCount(x->getLeft())+_nodeCount(x->getRight());
    }
    
    void _printLeaves(Nodo<T>* x,ostream& out){
		if(!x) return ;
		if(!x->getRight() && !x->getLeft()){
			out << x->getKey() << " ";
			return;
		}
		if(x->getLeft()) _printLeaves(x->getLeft());
		if(x->getRight()) _printLeaves(x->getRight());	
	}
	
	int _rprof(T key,Nodo<T>* x){
		if(x==NULL) return -1;
		if(x->getKey() == key) return 0;
		int p;
		if(key < x->getKey()) return p =_rprof(key,x->getLeft());
		else return p =_rprof(key,x->getRight());
		if(p>0) return p+1;
		else return -1;
	}
	
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
    
    int _raltezza(Nodo<T>* x){
		if(x==NULL) return -1;
		int pleft = _raltezza(x->getLeft());
		int pright= _raltezza(x->getRight());
		if(pleft<pright) return pright +1;
		else return pleft+1; 
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
    
    T _peso(Nodo<T>* x){
	    Nodo<T>* tmp = _min(x);
	    if(tmp == x && !tmp->getRight()) return tmp->getKey();
	    T ret=0;
	    while(tmp && tmp->getKey() < x->getKey()){
	        ret+= tmp->getKey();
	        tmp = _successore(tmp);
	    }
	    Nodo<T>* tmp1 = _max(x);
	    while(tmp1 && tmp1->getKey() > x->getKey()){
	        ret+=tmp1->getKey();
	        tmp1 = _predecessore(tmp1);
	    }
	    return ret+x->getKey();
	}
    
public:
    BST() {
        n = 0;
        root = current = NULL;
        d = new List<T>();
    }
    
    BST<T>& ins(T& key) {
        Nodo<T>* x = new Nodo<T>(key);
        Nodo<T>* tmp = root;
        Nodo<T>* p = NULL;
        while(tmp) {
            p = tmp;
            if(key <= tmp->getKey()) tmp = tmp->getLeft();
            else tmp = tmp->getRight();
        }
        if(!p) root = x;
        else {
            x->setParent(p);
            if(key <= p->getKey())
                p->setLeft(x);
            else p->setRight(x);
        }
        n++;
        return *this;
    }
    

    BST<T>& canc(T key) {
        Nodo<T> *x = _search(root, key);
        if(!x) return *this;
        if(x->getLeft() && x->getRight()) {
            //caso 3
            Nodo<T> *y = _successore(x);
            //cout << x->getKey() << endl;
            //cout << y->getKey() << endl;
            T& v = x->getKey();
            x->setKey(y->getKey());
            y->setKey(v);
            //cout << x->getKey() << endl;
            //cout << y->getKey() << endl;
            x = y;
        }
        //casi 1 e 2
        Nodo<T>* z = x->getLeft();
        if(!z) z = x->getRight();
        Nodo<T> *p = x->getParent();
        if(!p) root = z;
        else {
            if(p->getLeft()==x)
                p->setLeft(z);
            else p->setRight(z);
        }
        if(z) z->setParent(p);
        n--;
        return *this;
    }
    
    int search(T key){
        return (_search(root,key)!=NULL);
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
		Nodo<T> *x = _search(root,key);
		if(x){
			Nodo<T>* tmp = _successore(x);
			if(tmp) return tmp->getKey();
			else return NULL;
		}
		return NULL;
	}
	
	T predecessore(T key){
		Nodo<T> *x = _search(root,key);
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
		Nodo<T> *x = _search(root,k1);
		Nodo<T> *y = _search(root,k2);
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
	
	int getlevel(T key){
	    Nodo<T>* x = _search(key,root);
	    return _prof(key,root);
	}	
	
	void printlevel(int k,ostream& out){
		Nodo<T>* tmp = _min(root);
		while(tmp){
			if(_prof(tmp->getKey(),root)==k)
			out << tmp->getKey() << " ";
			tmp = _successore(tmp);
		}
		out << endl;		
	}
	
    int size(){
        return n;
    }
    
    int isEmpty(){
        return (n==0);
    }
    
    int leafCount() {
        return _leafCount(root);
    }
    
    void naturalFill(T *v, int n) {
        if(n!=this->n) {
            cout << "Natural Fill non eseguibile" << endl;
            return;
        }
        Nodo<T>* tmp = _min(root);
        
        /*for(int i=0; i<n; i++) {
            Nodo<T>* y = _successore(tmp);
            tmp->setKey(v[i]);
            tmp = y;
        }*/
        
        int i=0;
        while(tmp!=NULL) {
            tmp->setKey(v[i]);
            tmp = _successore(tmp);;
            i++;
        }
    }
    
    int distSuccessore(T key){
        int dist = 0;
        Nodo<T> *x = _search(root,key);
        if(!x) return 0;
        Nodo<T>* t = _successore(x);
        if(t){
            if(x->getRight()){
                Nodo<T>* tmp = x->getRight();
                dist = 1;
                while(tmp->getLeft()){
                    tmp = tmp->getLeft();
                    dist = dist +1;
                }
                return dist;
            }
            else{
                Nodo<T>* p = x->getParent();
                dist = 1;
                while(p && p->getRight()==x) {
                x = p;
                p = p->getParent();
                dist = dist +1;
            }
            return dist;
        }     
    }
    else return 0; 
    }
    
     T peso(T key){
        Nodo<T> *x = _search(root,key);
        if(!x) return 0;
        T ret = _peso(x);
        return ret;
   }
    
};

template <class H> ostream& operator<<(ostream& out, const BST<H>& t) {
    BST<H> tmp = t;
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



