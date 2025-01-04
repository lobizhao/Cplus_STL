//
// Created by admin on 2024/12/4.
//

#ifndef CPLUS_STL_MY_STACK_H
#define CPLUS_STL_MY_STACK_H
#include <iostream>
#include <string>
#include <vector>
/*( for stack function contains
 *  push
 *  top
 *  pop
 *  empty
 *  size
 */
using namespace std;

template <typename T>

class my_stack {
private:
    vector<T> elements;
public:
    my_stack();
    void push(T ele);
    size_t size();
    T top();
    void pop();
    bool isEmpty();

};

template <typename T>
class MinStack{
private:
    vector<T> elements;
    vector<T> minStack;
public:
    MinStack();
    void push(T ele);
    void pop();
    T top();
    T getMin();


};

template <typename T>
class MaxStack{
private:
    vector<T> elements;
    vector<T> maxStack;
public:
    MaxStack();
    void push(T ele);
    void pop();
    T top();
    T peekMax();
    T popMax();
};


#endif //CPLUS_STL_MY_STACK_H
