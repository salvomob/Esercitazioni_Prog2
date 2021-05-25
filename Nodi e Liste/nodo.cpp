#include<iostream>
template <class T> class Nodo{
private:
	T key;
	Nodo<T>* next;
		
public:

	Nodo(T key)
	{
		this->key = key;
		this->next = nullptr;
	}
	
	~Nodo(){}
	
	void setKey(T key)
	{
		this->key = key;
	}
	
	void setNext(Nodo<T>* next)
	{
		this->next = next;
	}
	
	T getKey() const
	{
		return this->key;
	}
	
	Nodo<T>* getNext() const
	{
		return this->next;
	}
};

	template <class T> std::ostream& operator<<(std::ostream& os,const Nodo<T>& n)
	{
		os << "Key Nodo : " << n.getKey() << "\n";
		os << "Next Nodo : " << n.getNext() << "\n";
		return os;
	}
