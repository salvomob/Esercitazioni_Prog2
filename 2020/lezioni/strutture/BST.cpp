#include<iostream>
using namespace std;
//implementazione di un albero binario di ricerca
//N chiavi ->O(n) -> visita inorder
//O(NlogN)

template <class T> class Nodo {
private:
	T *key;
	Nodo<T> *left,*right;
	Nodo<T> *parent;
public:
	Nodo(T key){
		this->key= new T(key);
		left = right = parent = NULL;
	}
	T getKey(){return *key;}
	Nodo<T>* getLeft(){return left;}
	Nodo<T>* getRight(){return right;}
	Nodo<T>* getParent(){return parent;}
	void setKey(T key){ this->key =new T(key);}
	void setLeft(Nodo<T>* left){this->left=left;}
	void setRight(Nodo<T>* right){this->right = right;}
	void setParent(Nodo<T>* parent){this->parent = parent;}
};

template <class T> class BST {
private:
	int n;//numero di nodi contenuti nella struttura dati
	Nodo<T> *root, *current;
	//funzione iterativa che realizza la ricerca di una key all'interno del sottoalbero radicato in x
	Nodo<T>* _search(T key,Nodo<T>* x){
		Nodo<T> *tmp=x;
		while(tmp!= NULL && tmp->getKey()!= key){
			if(key < tmp->getKey()) tmp = tmp->getLeft();
			else tmp = tmp->getRight();
		}
		return tmp;
	}
	//funzione ricorsiva che realizza la ricerca di una key all'interno del sottoalbero radicato in x
	Nodo<T>* _rsearch(T key,Nodo<T>* x){
		if(!x) return NULL;
		if(x->getKey()==key) return x;
		if(key < x->getKey()) return _rsearch(key, x->getLeft());
		else return _rsearch(key, x->getRight());
	}
	//funzione iterativa che trova il minimo di un sottoalbero radicato in un nodo
	Nodo<T>* _min(Nodo<T>* x){
		if(!x) return NULL;
		Nodo<T> *tmp = x;
		while(tmp->getLeft())	tmp= tmp->getLeft();
		return tmp;
	}
	//funzione ricorsiva che trova il minimo di un sottoalbero radicato in un nodo
	Nodo<T>* _rmin(Nodo<T>* x){
		if(!x) return NULL;
		if(!x->getLeft()) return x;
		return _rmin(x->getLeft());
	}
	//funzione iterativa che trova il massimo di un sottoalbero radicato in un nodo
	Nodo<T>* _max(Nodo<T>* x){
		if(!x) return NULL;
		Nodo<T> *tmp = x;
		while(tmp->getRight())	tmp= tmp->getRight();
		return tmp;
	}
	//funzione ricorsiva che trova il minimo di un sottoalbero radicato in un nodo
	Nodo<T>* _rmax(Nodo<T>* x){
		if(!x) return NULL;
		if(!x->getRight()) return x;
		return _rmax(x->getRight());
	}
	//funzione per il calcolo del nodo successore ad un nodo passato in input
	Nodo<T>* _successore(Nodo<T> *x){
		if(!x) return NULL;
		if(x->getRight()) return _min(x->getRight());	
		Nodo<T> *tmp = x->getParent();
		while(tmp && tmp->getKey() < x->getKey()) tmp = tmp->getParent();
		return tmp;
	}
	//funzione per il calcolo del nodo predecessore ad un nodo passato in input
	Nodo<T>* _predecessore(Nodo<T> *x){
		if(!x) return NULL;
		if(x->getLeft()) return _max(x->getLeft());	
		Nodo<T> *tmp = x->getParent();
		while(tmp && tmp->getKey() >= x->getKey()) tmp = tmp->getParent();
		return tmp;
	}
	//procedura ricorsiva che calcola la profondità del nodo che contiene la chiave key nel sottoalero radicato in x
	int _rprof(T key,Nodo<T>* x){
 		if(!x) return -1;
 		if(x->getKey() == key) return 0;
 		int p;
 		if(key < x->getKey()) return p=_rprof(key,x->getLeft());
 		else return p= _rprof(key,x->getRight());
 		if(p>0) return p+1;
 		return -1;	
 	}																	
 	//procedura iterativa che calcola la profondità del nodo che contiene la chiave key nel sottoalero radicato in x
 	int _prof(T key,Nodo<T>* x){
 		if(!x) return -1;
 		int p = 0;
 		Nodo<T> *tmp = x;
 		while(tmp && tmp->getKey()!=key){
 			if(key < tmp->getKey()) tmp = tmp->getLeft();
 			else tmp = tmp->getRight();
 			p++;
 		}
 		if(!tmp) return -1;
 		return p;	
 	}
 	//procedura iterativa per calcolare l'altezza di un sottoalbero radicato in x
 	int _altezza(Nodo<T>* x){//O(NlogN)caso ottimo,ossia albero bilanciato caso pessimo O(n^2)-> in entrambi i casi, complessità abbastanza alta
		Nodo<T>* tmp = _min(x);//si parte dal minimo del sottoalbero --> O(n)
		int p=0;
		while(tmp!=NULL){//da verificare   --> O(n)
			int t = _prof(tmp->getKey(),x);//O(n)
			if(t>p) p =t;
			tmp = _successore(tmp);//O(n)
		} 
		return p;
	}
	//procedura ricorsiva per calcolare l'altezza di un sottoalbero radicato in x
 	int _raltezza(Nodo<T>* x){
		if(x==NULL) return -1;
		int pleft = _raltezza(x->getLeft());
		int pright= _raltezza(x->getRight());
		if(pleft<pright) return pright +1;
		else return pleft+1; 
	}
	
	void _preorder(Nodo<T> *x){
		if(x){
		cout<< x->getKey() << " ";
		_preorder(x->getLeft());
		_preorder(x->getRight());
		}		
	}
	void _inorder(Nodo<T> *x){
		if(x){
		_inorder(x->getLeft());
		cout<< x->getKey() << " ";		
		_inorder(x->getRight());
		}
	}
	void _postorder(Nodo<T> *x){
		if(x){
		_postorder(x->getLeft());
		_postorder(x->getRight());
		cout<< x->getKey() << " ";
		}	
	}
	void _preorder(ostream& os,Nodo<T> *x){
		if(x){
			os<< x->getKey() << " ";
			_preorder(os,x->getLeft());
			_preorder(os,x->getRight());
		}		
	}
	void _inorder(ostream& os,Nodo<T> *x){
		if(x){
		_inorder(os,x->getLeft());
		os<< x->getKey() << " ";		
		_inorder(os,x->getRight());
		}
	}
	void _postorder(ostream& os,Nodo<T> *x){
		if(x){
		_postorder(os,x->getLeft());
		_postorder(os,x->getRight());
		os<< x->getKey() << " ";
		}	
	}
	
public:
	BST(){
		n=0;
		root = current = NULL;
	}

	BST<T>& ins(T key){
		Nodo<T>* tmp = root;//tmp serve per scorrere l'albero a partire dalla root
		Nodo<T>* parent = NULL;//nodo padre di x
		Nodo<T>* x = new Nodo<T>(key);//nodo da inserire nella struttura
		n++;
		while(tmp!=NULL){
			parent = tmp;//genitore del nodo tmp,ossia il nodo che lo precede
			if(key < tmp->getKey())
				tmp = tmp->getLeft();
			else
				tmp = tmp ->getRight();	
		}
		if(parent == NULL) {// l'albero non contiene nodi
			root = x;
			return *this;
		}
		//inseriamo il nodo x come figlio di parent
		if(key < parent->getKey())
			parent->setLeft(x);
		else 
			parent->setRight(x);
		x->setParent(parent);
		return *this;
	}
	BST<T>& canc(T key){
		Nodo<T>* x = _search(key,root);
		if(x==NULL) return *this;
		if(x->getRight() && x->getLeft()){
			//caso 3 : sostituisco il nodo x con il suo successore
			Nodo<T>* s = _successore(x);
			x->setKey(s->getKey());
			s->setKey(key);
			x = s;
		}
		//caso 1 oppure 2
		Nodo<T>* p = x->getParent();
		Nodo<T>* y = x->getLeft();
		if(!y) y= x->getRight();
		if(p){
			if(key < p->getKey()) p->setLeft(y);
			else p->setRight(y);
		}
		else root = y;
		if(y) y->setParent(p);
		n--;
		return *this;	
	}
	T* min(){
		Nodo<T>* x = _rmin(root);
		if(x) return new T(x->getKey());
		return NULL;	
 		
 	}
	T* max(){
		Nodo<T>* x = _max(root);
		if(x) return new T(x->getKey());
		return NULL;	
 		
 	}
 	T* successore(T key){
 		Nodo<T> *x= _search(key,root);
 		if(x){
 			Nodo<T> *y = _successore(x);
 			if(y) return new T(y->getKey());
 		} 
 		return NULL;	
 	}
 	T* predecessore(T key){
 		Nodo<T> *x= _search(key,root);
 		if(x){
 			Nodo<T> *y = _predecessore(x);
 			if(y) return new T(y->getKey());
 		} return NULL;	
 	}
 	//calcola la profondità del nodo che contiene la chiave key
 	int prof(T key){
 		return _prof(key,root);		
 	}
	int altezza(){
		return _raltezza(root);
	}
	int search(T key){
		return _rsearch(key,root)!=NULL;
	}
	int isEmpty(){return (n==0);}
	int size(){return n;}
	void preorder(ostream& os){
		_preorder(os,root);
	}
	void postorder(ostream& os){
		_postorder(os,root);	
	}
	void inorder(ostream& os){
		_inorder(os,root);
	}
	void inorder_print(){//inorder iterativa
		Nodo<T>* tmp = _min(root);
		while(tmp!=NULL){
			cout<< tmp->getKey() << " ";
			tmp = _successore(tmp);
		}
		cout << endl;
	}
	void preorder_print(){
		
	}
	void postorder_print();  
	
	
	
	//iteratore(si tratta di una visita inorder iterativa)
	//si può creare un overloading usando le funzioni _pre,_post ed _in order 
	void reset(){
		current = _min(root);
	}
	int hasNext(){
		return (current!=NULL);
	}
	T* next(){
		if(hasNext()){
			T* e = new T(current->getKey());
			current = _successore(current);
			return e;
		}
		return NULL;
	}
};

ostream& operator<<(ostream& os,const BST<int>& t){
	BST<int> tmp = t;
	tmp.preorder(os);
	return os;
}

int main() {
	BST<int> *t = new BST<int>();
	t->ins(10).ins(5).ins(15).ins(2).ins(20).ins(8).ins(12);
	cout << *t << endl;
	
}



