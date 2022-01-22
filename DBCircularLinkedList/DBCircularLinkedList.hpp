//
//  DBCircularLinkedList.hpp
//  DBCircularLinkedList
//
//  Created by ПрЈ|Т@ on 2021/12/5.
//

#ifndef DBCircularLinkedList_hpp
#define DBCircularLinkedList_hpp

#include <iostream>
#include <stdio.h>

using namespace std;

template<class T> class CircularChain;

template<class T>
class CircularChainNode {
friend class CircularChain<T>;
private:
    T data;
    CircularChainNode<T> *next;
    CircularChainNode<T> *prev;
};

template<class T>
class CircularChain{
public:
    CircularChain();
    CircularChain(const CircularChain<T> &);
    ~CircularChain();
    void InsertFront(const T&);
    void InsertBack(const T&);
    void Delete(const T&);
    void IteratorFront();
    void IteratorBack();
    void Display();
    
private:
    CircularChainNode<T> *first;
    CircularChainNode<T> *last;
    int count;
};



#endif /* DBCircularLinkedList_hpp */

