#include <iostream>
#include <stdio.h>
#include "NStack.hpp"

using std::ostream;
using std::istream;
using std::endl;
using std::swap;
using std::copy;

NStack::NStack(int size):size(size)
{
    array = new int [size];
    top = -1;
}


NStack::~NStack(){
    delete [] array;
}


void NStack::Push(int d){
    if(isFull()){
        Resize();
    }
    
    array[++top] = d;
}


int NStack::Pop(){
    if(isEmpty()){
        std::cout << "The NStack is empty" << std::endl;
    }
    
    int del = array[top--];
    return del;
}


inline bool NStack::isEmpty(){
    if(top == -1) return true;
    else return false;
    
}


inline bool NStack::isFull(){
    if(top >= size) return true;
    else return false;
}


void NStack::Output(NStack s){
    NStack temp = s;
    NStack output = NStack(temp.size);
    while(temp.top != -1){
        output.Push(temp.Pop());
    }
    
    while(output.top != -1){
    	std::cout << output.Pop();
	}
}


bool NStack::Remove(NStack &s, int d){
	NStack temp = NStack(s.size);
	int rm_idx = -1;
    for(int i=0; i<s.top+1; i++){
    	if(d == s.array[i])
    		rm_idx = i;
	}
	
	while(rm_idx <= s.top){
		temp.Push(s.Pop());
	}
	
	temp.Pop();
	while(temp.top>-1){
		s.Push(temp.Pop());		
	}
	
	if(rm_idx == -1) return false;
	else return true;

}


void NStack::Sort(NStack &s){
    for(int i=0; i<s.top+1; i++){
        int j = i;
        for(int k=i+1; k<s.top+1; k++){
            if(s.array[k]<s.array[j])
                j = k;
        }
        swap(s.array[i], s.array[j]);
    }
    std::cout << s;
}


void NStack::Resize(){
    NStack ns(*this);
    int newSize;
    newSize = size * 2;
    int *temp = new int [newSize];
    copy(ns.array, ns.array+ns.top, temp);
    delete [] ns.array;
    ns.array = temp;
}


ostream &operator<<(ostream &os, const NStack &ns)
{
    for(int i=0; i<=ns.top; i++){
        os << ns.array[i];
    }
}


