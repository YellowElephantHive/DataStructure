//
//  DBCircularLinkedList.cpp
//  DBCircularLinkedList
//
//  Created by ПрЈ|Т@ on 2021/12/5.
//

#include <stdio.h>
#include <iostream>
#include "DBCircularLinkedList.hpp"

using namespace std;

template<class T>
CircularChain<T>::CircularChain()
{
    first = NULL;
    last = NULL;
    count = 0;
};

// copy constructor
template<class T>
CircularChain<T>::CircularChain(const CircularChain<T> &list)
{	
	/*
    if(first != NULL){
    	~CircularChain();
	}
	*/
    
    if(list.first != NULL){
        first = NULL;
        last = NULL;
        count = 0;
    }
    else{
        CircularChainNode<T> *cur1, *cur2;
        first = new CircularChainNode<T>;
        first -> data = list.first -> data;
        cur1 = first;
        cur2 = list.first;
        cur2 = cur2 -> next;
        while (cur2 != list.first) {
            cur1 -> next = new CircularChainNode<T>;
            cur1 -> next -> data = cur2 -> data;
            cur1 -> next -> prev = cur1;
            cur1 = cur1 -> next;
            cur2 = cur2 -> next;
        }
        last = cur1;
        last -> next = first;
        first -> prev = last;
        count = list.count;
    }
};

template<class T>
CircularChain<T>::~CircularChain()
{
    CircularChainNode<T> *temp;
    if(first==NULL){
        return;
    }
    else{
        do{
            temp = first;
            last = first -> next;
            delete temp;
            count--;
            
        } while(last!=first);
    }
    first = NULL;
    last = NULL;
    count = 0;
};

template<class T>
void CircularChain<T>::InsertFront(const T& val)
{
    CircularChainNode<T> *newNode;
    newNode = new CircularChainNode<T>;
    if(first==NULL){
        newNode -> data = val;
        first = last = newNode;
        newNode -> prev = last;
        newNode -> next = first;
    }
    else{
        newNode -> data = val;
        newNode -> next = first;
        newNode -> prev = last;
        first -> prev = newNode;
        last -> next = newNode;
        first = newNode;
            
    }
    count++;
};

template<class T>
void CircularChain<T>::InsertBack(const T& val)
{
    CircularChainNode<T> *newNode;
    newNode = new CircularChainNode<T>;
    if(first==NULL){
        newNode -> data = val;
        first = last = newNode;
        newNode -> prev = last;
        newNode -> next = first;
    }
    else{
        newNode -> data = val;
        newNode -> prev = last;
        last -> next = newNode;
        newNode -> next = first;
        first -> prev = newNode;
        last = newNode;
        
    }
    count++;
}

template<class T>
void CircularChain<T>::Delete(const T &val){
    int len = count;
    CircularChainNode<T> *p, *temp, *q;
    if(first==NULL)
        return;
    
    p = new CircularChainNode<T>;
    p = first;
    q = first;
    while(p -> data != val && len != 0){
        if(p -> next == first)
            cout << " The value is not found " << endl;
        
        q = p;
        p = p -> next;
        len--;
    }
    
    if(p -> next == first && q == NULL){
        first = NULL;
        delete p;
        count--;
    }
    
    if(p == first){
        p == first;
        first = first->next;
        first->prev = last;
        last->next = first;
        delete p;
    }
    else if (p -> next == first){
        q -> next = first;
        first -> prev = q;
        last = q;
        delete p;
    }
    else{
        q = first;
        temp = p -> next;
        q -> next = temp;
        temp -> prev = q;
        delete p;
    }
    count--;
}

template<class T>
void CircularChain<T>::IteratorFront()
{
    CircularChainNode<T> *cur;
    cur = first;
    do{
        if(cur == NULL){
        	cout << "list is empty" << endl;
		}
        else{
            cout << cur -> data << " ";
            cur = cur -> next;
        }
            
    } while(cur != first);
};

template<class T>
void CircularChain<T>::IteratorBack()
{
    CircularChainNode<T> *cur;
    cur = last;
    do{
        if(cur == NULL) cout << "list is empty" << endl;
        else{
            cout << cur -> data << " ";
            cur = cur -> prev;
        }
            
    } while(cur != last);

}

template<class T>
void CircularChain<T>::Display()
{
	CircularChainNode<T> *cur;
	cur = first;
	if(first==NULL){
		cout << "The list is empty" << endl;
	}
	else{
		do{
			cout << cur -> data << " ";
			cur = cur -> next;
		} while(cur!=first);
	}
}

