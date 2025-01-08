
#include <iostream>

template<typename T>
class my_queue{
private:
    size_t capacity;
    size_t frontPtr;
    size_t backPtr;
    size_t curSize;
    T* arr;

    void expand(){
        size_t newCapacity = capacity * 2;
        T* newArr = new T[newCapacity];

        for(size_t i =0; i< curSize; i++){
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;

        capacity = newCapacity;
        //set two pointer
        frontPtr =0;
        backPtr = curSize;
    }
public:
    my_queue(): capacity(4), frontPtr(0), backPtr(0), curSize(0), arr(new T[capacity]){}

    my_queue(size_t initSize):capacity(initSize), frontPtr(0), backPtr(0), curSize(0), arr(new T[capacity]){}

    my_queue(size_t initSize, T& ele):capacity(initSize), frontPtr(0), backPtr(0), curSize(0), arr(new T[capacity]){
        for(int i=0; i<initSize; i++){
            arr[i] = ele;
        }
    }

    //there are also something like copy/ copy operate constructor
    ~my_queue(){
        delete[] arr;
    }

    void push(T ele){
        if(curSize == capacity){
            expand();
        }
        arr[backPtr] = ele;
        curSize++;
    }

    size_t size(){
        std::cout << curSize <<std::endl;
        return curSize;
    }
    T& front(){
        if(curSize == 0){
            throw std::out_of_range("this is empty queue");
        }
        std::cout << arr[frontPtr] <<std::endl;
        return arr[frontPtr];
    }

    T& back(){
        if(curSize == 0){
            throw std::out_of_range("this is empty queue");
        }
        std::cout << arr[backPtr] << std::endl;
        return arr[backPtr];
    }

    void pop(){
        if(curSize == 0){
            throw std::out_of_range("this is empty queue");
        }
        frontPtr += 1;
        curSize--;
    }

    bool isEmpty(){
        if(curSize == 0){
            std::cout << "true" << std::endl;
            return true;
        }else{
            std::cout << "false" << std::endl;
            return false;
        }
    }
};