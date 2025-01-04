#ifndef CPLUS_STL_MY_STACK_H
#define CPLUS_STL_MY_STACK_H

#include <iostream>
#include <string>

/*( for stack function contains
 *  push
 *  top
 *  pop
 *  empty
 *  size
 */
template <typename T>
class my_stack {
private:
    int idx;
    int arrSize;
    //dynamic new array
    T* arr;
public:
    my_stack():idx(-1), arrSize(2),arr(new T[arrSize]){}
    ~my_stack(){
        delete[] arr;
    }

    void push(T ele){
        if(idx == arrSize-1){
            arrSize *= 2;
            //update size, resize process
            T* newArr = new T[arrSize];
            for(int i=0; i<idx; i++){
                newArr[i] = arr[i];
            }

            delete[] arr;
            arr = newArr;
        }

        idx += 1;
        arr[idx] = ele;
    }

    size_t size(){
        return idx+1;
    }
    T top(){
        if(isEmpty()){
            throw std::runtime_error("Stack is empty");
        }
        return arr[idx];

    }
    void pop(){
        if(isEmpty()){
            std::cout <<"Nothing in stack" << std::endl;
        }else{
            T theTpo = arr[idx];
            idx -= 1;
            std::cout << theTpo << " removed" << std::endl;
        }
    }
    bool isEmpty(){
        return idx == -1;
    }
};

#endif //CPLUS_STL_MY_STACK_H
