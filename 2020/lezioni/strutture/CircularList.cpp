#include <iostream>
using namespace std;

/*
 
                             head
 [3] -> [5] -> [7] -> [12] -> [4]
  ^                             |
  <-----------------------------

 */


template <class T> class Nodo {
private:
    T* key;
    Nodo<T> *next;
public:
    Nodo(T key) {
        this->key = new T(key);
        next =  NULL;
    }
    void setKey(T key) {*(this->key) = key;}
    void setNext(Nodo<T>* next) {this->next = next;}
    T getKey() { return *key;}
    Nodo<T>* getNext() { return next;}
};


template <class T> class CircularList {
private:
    int n;
    Nodo<T>* current, *head;
    int iterations;

    Nodo<T>* _search(T key) {
        int iter = 0;
        Nodo<T>* tmp = head;
        while(iter<n && tmp->getKey()!=key) {
            tmp = tmp->getNext();
            iter++;
        }
        if(iter<n) return tmp;
        return NULL;
    }

    Nodo<T>* _searchPrev(T key) {
        // restituisce il nodo che precede quello che contiene la chiave key
        int iter = 0;
        Nodo<T>* tmp = head;
        while(iter<n && tmp->getNext()->getKey()!=key) {
            tmp = tmp->getNext();
            iter++;
        }
        if(iter<n) return tmp;
        return NULL;
    }

    
public:
    CircularList() {
        n = 0;
        head = NULL;
        current = NULL;
        iterations = 0;
    }
    
    void moveHead() {
        if(head) head = head->getNext();
    }
    
    CircularList<T>& ins(T key) {
        // ... [head] -> [x] -> [y] ...
        //inserimento da farsi alla destra del nodo head
        Nodo<T>* x = new Nodo<T>(key);
        if(head) {
            Nodo<T>* y = head->getNext();
            x->setNext(y);
            head->setNext(x);
        }
        else {
            x->setNext(x);
            head = x;
        }
        n++;
        return *this;
    }
    
    CircularList<T>& canc(T key) {
        //            head
        // ... [p] -> [x] -> [y] ...
        Nodo<T>* p = _searchPrev(key);
        if(p) {
            Nodo<T>* x = p->getNext();
            p->setNext(x->getNext());
            n--;
            if(head==x) head = x->getNext();
            if(n==0) head = NULL;
        }
        return *this;
    }

    int search(T key) {
        return (_search(key)!=NULL);
    }

    int isEmpty() {
        return (n==0);
    }
    
    //iteratore
    void reset() {
        current = head;
        iterations = 0;
    }
    
    int hasNext() {
        return (iterations < n);
    }
    
    T* next() {
        if(hasNext()) {
            T* tmp = new T(current->getKey());
            current = current->getNext();
            iterations++;
            return tmp;
        }
        return NULL;
    }
    
};

ostream& operator<<(ostream& os, const CircularList<int>& l) {
    CircularList<int> tmp = l;
    os << "{ ";
    tmp.reset();
    while(tmp.hasNext()) {
        os << *(tmp.next()) << " ";
    }
    os << "}";
    return os;
}

int main() {
    CircularList<int>* c = new CircularList<int>();
    cout << *c << endl;
    c->ins(3).ins(4).ins(12).ins(7).ins(5);
    cout << *c << endl;
    c->moveHead();
    c->moveHead();
    cout << *c << endl;
    c->ins(8);
    cout << *c << endl;
    cout << c->search(5) << endl;
    cout << c->search(3) << endl;
    cout << c->search(13) << endl;
    c->canc(12);
    cout << *c << endl;
    c->canc(5);
    cout << *c << endl;
    c->canc(7);
    cout << *c << endl;
    c->moveHead();
    cout << *c << endl;
    c->canc(3).canc(4).canc(8);
    cout << *c << endl;
    c->ins(3).ins(4).ins(12).ins(7).ins(5);
    cout << *c << endl;

}

