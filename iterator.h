#ifndef __iterator
#define __iterator

#include <string>
#include <algorithm>
#include <list>
#include <iostream>
#define PRINT(var_) {std::cout << #var_ << ": " << (var_) << std::endl;}

using namespace std;

template <class node, class T>
class superIterator {
private:
	node *node_ptr;
public:
	superIterator(node *n)
	{
		node_ptr = n;
	};
	T *next(){
		return node_ptr->get();
	};
	void operator++()
	{
		node_ptr = node_ptr->next();
	};
	superIterator operator++(int)
	{
		superIterator iter(*this);
		++(*this);
		return iter
	};
	bool operator==(superIterator const &i)
	{
		return node_ptr == i.node_ptr;
	};
	bool operator!=(superIterator const &i)
	{
		return !(*this == i);
	};
};

template <class T>
class element {
private:
	T object; // 
	element *next_node;
public:
	element(T const &t)
	{
		object = t;
		next_node = 0;
	};
	~element()
	{
		if (next_node)
			delete next_node;
	};
	element *next()	
	{
		cout << object << endl;
		return next_node;
	};
	T *get()
	{
		return &object;
	};
	void push(T const &t)
	{
		if (next_node)
			next_node->push(t);
		else
			next_node = new element(t);
	}
};
template <class T>

class aggregate {
public:
	typedef element<T> node;
	typedef superIterator<node, T> myIterator;
private:
	node *root;
public:
	aggregate()
	{
		root = 0;
	};
	~aggregate()
	{
		if (root) 
			delete root;
	};
	myIterator begin()
	{
		return myIterator(root);
	};
	myIterator end()
	{
		return myIterator(0);
	};
	void push(T const &t)
	{
		if (root)
			root->push(t);
		else
			root = new node(t);
	};
};

#endif