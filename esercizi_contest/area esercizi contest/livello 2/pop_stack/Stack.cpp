#include <iostream>
using namespace std;


/*
 LIFO = LAST IN FIRST OUT
 PILA, STACK
 
             t
   [ x y z w _ _ _ ] ----> pop()
                     <---- push()
 */



template <class T> class Stack {
private:
    int n, len, current;
    int top;
    T** s;
    
public:
    Stack() {
        n = 0;
        len = 1000; // lunghezza di default del vettore
        s = new T*[len];
        top = 0;
    }
    Stack(int len) {
        n = 0;
        this->len = len;
        s = new T*[len];
        top = 0;
    }
    
    Stack<T>& push(T key) { //O(1)
        if(n<len) {
            s[top] = new T(key);
            top++;
            n++;
        }
        return *this;
    }
    
    T* pop() {  //O(1)
        if(n>0) {
            T* tmp = s[top-1];
            top--;
            n--;
            return tmp;
        }
        return NULL;
    }
    
    int isEmpty() {
        return (n==0);
    }
    int size(){return n;}
    //iteratore
    void reset() {
        current = top-1;
    }
    
    int hasNext() {
        return (current >= 0);
    }
    
    T* next() {
        if(hasNext()) {
            T* tmp = s[current];
            current--;
            return tmp;
        }
        return NULL;
    }
    
};

template <class T> ostream& operator<<(ostream& os, const Stack<T>& s) {
    Stack<T> tmp = s;
    tmp.reset();
    while(tmp.hasNext()) {
        os << *(tmp.next());
    }
    return  os;
}

/*
int main() {
	Stack<string> *s = new Stack<string>();
	s->push("selene").push("salvo").push("peppino").push("mariabranca");
	cout << *s << endl;
	s->pop();
	s->pop();
	cout << *s << endl;

}
*/
