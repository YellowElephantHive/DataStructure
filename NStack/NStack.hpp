
#ifndef NStack_hpp
#define NStack_hpp

#include <iostream>
#include <stdio.h>

class NStack
{
public:
    NStack(int);
    ~NStack();
    void Push(int);
    int Pop();
    inline bool isEmpty();
    inline bool isFull();
    void Output(NStack);
    bool Remove(NStack &, int);
    void Sort(NStack &);
    
    friend std::ostream &operator<<(std::ostream &, const NStack &);
    //friend std::istream &operator>>(std::istream &, NStack &);
    
private:
    void Resize();
    int top, size;
    int *array;
};



#endif /* Nstack_hpp */

