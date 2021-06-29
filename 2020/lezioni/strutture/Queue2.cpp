#include <iostream>
#include "Stack.cpp"
using namespace std;

/*
    Implementazione di una coda attraverso
    l'utilizzo di due stack
 */

/*
 s1 [ 8 2 9         ]  <-
 s2 [ 9 2 8         ]  <-
 s3 [ 7 4 3 8 2 9   ]
 */


template <class T> class Queue {
private:
    Stack<T> *s1, *s2, *s3; // LIFO
    void _travasa(Stack<T>* a, Stack<T>* b) {
        while(!a->isEmpty()) {
            T* e = a->pop();
            b->push(*e);
        }
    }
public:
    Queue(){
        s1 = new Stack<T>();
        s2 = new Stack<T>();
        s3 = new Stack<T>();
    }
    
    Queue<T>& enqueue(T key) { // O(1)
        s1->push(key);
        return *this;
    }
    
    T* dequeue() { // O(1) in media
        if(isEmpty()) return NULL;
        if(s2->isEmpty()) _travasa(s1,s2);
        T* e = s2->pop();
        return e;
    }

    int isEmpty() {
        return (s2->isEmpty() && s1->isEmpty());
    }
    
    int size() {
        return (s2->size() + s1->size());
    }
    
    //iteratore
    void reset() {
        while(!s3->isEmpty()) s3->pop();
        Stack<T>* c1 = new Stack<T>(*s1);
        Stack<T>* c2 = new Stack<T>(*s2);
        _travasa(c2, s3);
        _travasa(c1, c2);
        _travasa(c2, s3);
        s3->reset();
    }
    
    int hasNext() {
        return s3->hasNext();
    }
    
    T* next() {
        return s3->next();
    }
    
    
};

ostream& operator<<(ostream& os, const Queue<int>& q) {
    Queue<int> tmp = q;
    os << "[ ";
    tmp.reset();
    while(tmp.hasNext()) {
        int* e = tmp.next();
        os << *e << " ";
    }
    os << "] ";
    return  os;
}


int main() {
    Queue<int>* q = new Queue<int>();
    cout << *q << endl;
    q->enqueue(5).enqueue(3).enqueue(8).enqueue(4);
    cout << *q << endl;
    cout << *(q->dequeue()) << endl;
    cout << *q << endl;
    cout << q->size() << endl;
    q->enqueue(24);
    cout << *q << endl;
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    cout << *q << endl;
    q->enqueue(5).enqueue(3).enqueue(8).enqueue(4);
    cout << *q << endl;
}

