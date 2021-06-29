#include <iostream>
using namespace std;


/*
 
 Header -> [ ] -> [7] -> [10] -> [13] -> [15] -> [ ] -> NULL
 NULL   <-     <-     <-      <-      <-      <-     <- Trailer
 
 Header -> [ ] -> [ ] -> NULL
 NULL   <-     <-     <- Trailer
 
 
 Lista : Lista Vuota
 Lista : [x] -> Lista
 
 */



template <class T> class Nodo {
private:
    T* key;
    Nodo<T> *next, *prev;
public:
    Nodo(T key) {
        this->key = new T(key);
        next = prev = NULL;
    }
    Nodo() {
        this->key = NULL;
        next = prev = NULL;
    }
    void setKey(T key) {*(this->key) = key;}
    void setNext(Nodo<T>* next) {this->next = next;}
    void setPrev(Nodo<T>* prev) {this->prev = prev;}
    T getKey() { return *key;}
    Nodo<T>* getNext() { return next;}
    Nodo<T>* getPrev() { return prev;}
};


template <class T> class RecursiveLinkedList {
private:
    int n;
    Nodo<T> *Header, *Trailer, *current;

    Nodo<T>* _search(Nodo<T>* head, T key) {
        Nodo<T> *tmp = head;
        while(tmp!=Trailer && tmp->getKey()<key) tmp=tmp->getNext();
        if(tmp==Trailer) return NULL;
        if(tmp->getKey()==key) return tmp;
        return NULL;
    }
    
    Nodo<T>* _search(T key) {
        return _search(Header->getNext(), key);
    }
    
    void _ins(Nodo<T>* head, T key) {
        if(head==Trailer || head->getKey()>key) {
            //devo inserire la chiave prima di head
            Nodo<T>* x = new Nodo<T>(key);
            x->setNext(head);
            x->setPrev(head->getPrev());
            head->getPrev()->setNext(x);
            head->setPrev(x);
        }
        else _ins(head->getNext(), key);
    }
    
public:
    RecursiveLinkedList() {
        n = 0;
        Header = new Nodo<T>();
        Trailer = new Nodo<T>();
        Header->setNext(Trailer);
        Trailer->setPrev(Header);
        current = NULL;
    }
    
    RecursiveLinkedList<T>& ins(T key) {
        _ins(Header->getNext(), key);
        n++;
        return *this;
    }
    
    //  .. [y] -> [x] -> [z] -> ..
    //  <-     <-     <-
    RecursiveLinkedList<T>& canc(T key) {
        Nodo<T>* x = _search(key);
        if(x!=NULL) {
            Nodo<T>* y = x->getPrev();
            Nodo<T>* z = x->getNext();
            y->setNext(z);
            z->setPrev(y);
            n--;
        }
        return *this;
    }
    
    int search(T key) {
        return (_search(key)!=NULL);
    }
    
    int isEmpty() {
        return (n==0);
    }
    
    // iteratore
    void reset() {
        current = Header->getNext();
    }
    
    int hasNext() {
        return (current!=Trailer);
    }
    
    T* next() {
        if(hasNext()) {
            T* tmp = new T(current->getKey());
            current = current->getNext();
            return tmp;
        }
        else return NULL;
    }
    
};

ostream& operator<<(ostream& os, const RecursiveLinkedList<int>& l) {
    RecursiveLinkedList<int> tmp = l;
    os << "{ ";
    tmp.reset();
    while(tmp.hasNext()) {
        os << *(tmp.next()) << " ";
    }
    os << "}";
    return os;
}

int main() {
    RecursiveLinkedList<int> *l = new RecursiveLinkedList<int>();
    cout << *l << endl;
    l->ins(7);
    cout << *l << endl;
    l->ins(10);
    l->ins(14);
    cout << *l << endl;
    l->ins(12);
    l->ins(9);
    cout << *l << endl;
    l->ins(5);
    cout << *l << endl;
    l->canc(8);
    cout << *l << endl;
    l->canc(10).canc(14).canc(5);
    cout << *l << endl;
}

