#include<iostream>
using namespace std;

template <class T> class Queue {
private:
    int n, len, current, iterations;
    int head, tail;
    T** q;
    
public:
    Queue() {
        n = 0;
        len = 100; // lunghezza di default del vettore
        q = new T*[len];
        head = 0;
        tail = 0;
        iterations = 0;
    }
    Queue(int len) {
        n = 0;
        this->len = len;
        q = new T*[len];
        head = 0;
        tail = 0;
        iterations = 0;
    }

    Queue<T>& enqueue(T key) { //O(1)
        if(n<len) {
            q[tail] = new T(key);
            tail++;
            if(tail==len) tail = 0;
            // tail = (tail+1)%len;
            n++;
        }
        return *this;
    }
    
    T* dequeue() {  //O(1)
        if(n>0) {
            T* tmp = q[head];
            head++;
            if(head==len) head=0;
            n--;
            return tmp;
        }
        return NULL;
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
            T* tmp = q[current];
            current++;
            if(current==len) current=0;
            iterations++;
            return tmp;
        }
        return NULL;
    }
    
};

template <class T> ostream& operator<<(ostream& os, const Queue<int>& q) {
    Queue<T> tmp = q;
    os << "[ ";
    tmp.reset();
    while(tmp.hasNext()) {
        int* e = tmp.next();
        os << *e << " ";
    }
    os << "] ";
    return  os;
}
