#include <iostream>
#include <fstream>
using namespace std;

// soluzione del problema common-ancestor contenuto all'interno del Coding Contest

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
    
    Nodo<T>* _search(Nodo<T>* x, T key) {
        if(!x) return NULL;
        if(x->getKey()==key) return x;
        if(key <= x->getKey())
            return _search(x->getLeft(), key);
        else return _search(x->getRight(), key);
    }
    
    Nodo<T>* _min(Nodo<T>* x) {
        if(!x) return NULL;
        if(!x->getLeft()) return x;
        return _min(x->getLeft());
    }
    
    Nodo<T>* _successore(Nodo<T>* x) {
        if(!x) return NULL;
        if(x->getRight())
            return _min(x->getRight());
        Nodo<T>* p = x->getParent();
        while(p && p->getKey()<x->getKey()) {
            p = p->getParent();
        }
        return p;
    }
    
    void _inorder(Nodo<T>* x) {
        if(!x) return;
        _inorder(x->getLeft());
        cout << x->getKey() << " ";
        _inorder(x->getRight());
    }
    
    int _leafCount(Nodo<T>* x) {
        if(!x) return 0;
        if(!x->getLeft() && !x->getRight()) return 1;
        return _leafCount(x->getLeft()) + _leafCount(x->getRight());
    }
    
public:
    BST() {
        n = 0;
        root = current = NULL;
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
    
    void inorder() {
        _inorder(root);
        cout << endl;
    }
    
    T* min() {
        Nodo<T>* x = _min(root);
        if(x) return &x->getKey();
        return NULL;
    }

    T* successore(T key) {
        Nodo<T>* x = _search(root, key);
        if(x) {
            Nodo<T>* y = _successore(x);
            if(y) return &y->getKey();
        }
        return NULL;
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
    
    int leafCount() {
        return _leafCount(root);
    }
    
    T commonAncestor(T key1, T key2) {
        Nodo<T>* x = root;
        T k1 = key1<key2?key1:key2;
        T k2 = key1>=key2?key1:key2;
        while(!(k1<=x->getKey() && k2>=x->getKey())) {
            if(k1<x->getKey()) x=x->getLeft();
            else  x=x->getRight();
        }
        return x->getKey();
    }
    
};



int main() {
    /*BST<int>* t = new BST<int>();
    int e1 = 6;
    int e2 = 9;
    int e3 = 7;
    int e4 = 13;
    int e5 = 2;
    t->ins(e1).ins(e2).ins(e3).ins(e4).ins(e5);
    t->inorder();
    cout << t->commonAncestor(2,13) << endl;
    */
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");

    for(int task=0; task<100; task++) {
        string tipo;
        in >> tipo;
        int n;
        in >> n;
        if(tipo=="int") {
            BST<int>* t = new BST<int>();
            for(int i=0; i<n; i++) {
                char c,b;
                in >> c;
                in >> b;
                in >> b;
                in >> b;
                if(c=='i') {
                    int *e = new int(0);
                    in >> *e;
                    t->ins(*e);
                }
                else {
                    in >> b;
                    int e;
                    in >> e;
                    t->canc(e);
                }
            }
            int a,b;
            in >> a;
            in >> b;
            out << t->commonAncestor(a,b) << endl;
        }
        else {
            BST<double>* t = new BST<double>();
            for(int i=0; i<n; i++) {
                char c,b;
                in >> c;
                in >> b;
                in >> b;
                in >> b;
                if(c=='i') {
                    double *e = new double(0);
                    in >> *e;
                    t->ins(*e);
                }
                else {
                    in >> b;
                    double e;
                    in >> e;
                    t->canc(e);
                }
            }
            double a,b;
            in >> a;
            in >> b;
            out << t->commonAncestor(a,b) << endl;
        }
    }
    
    in.close();
    out.close();
    
}

