//
// Created by admin on 2025/1/4.
//
#include <iostream>
#ifndef CPLUS_STL_MY_VECTOR_H
#define CPLUS_STL_MY_VECTOR_H

template<typename T>
class my_vector{
private:
    size_t idx;
    size_t arrSize;
    T* arr;

    void resize(size_t newSize){
        T* newArr = new T[newSize];
        for(int i=0; i<idx; i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        arrSize = newSize;
    }
public:
    my_vector():idx(-1), arrSize(2), arr(new T[arrSize]){}
    my_vector(int a):idx(-1), arrSize(2), arr(new T[arrSize]){
        resize(a);
    }
    my_vector(int a, T ele):idx(-1), arrSize(2), arr(new T[arrSize]){
        resize(a);
        for(int i=0; i<a; i++){
            arr[i] = ele;
        }
    }
    ~my_vector(){
        delete[] arr;
    }

    void push_back(T ele){
        if(idx == arrSize -1){
            arrSize *= 2;
            T* newArr = new T[arrSize];
            for(int i=0; i<=idx; i++){
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        idx += 1;
        arr[idx] = ele;
    }

    //void insert(int index, T ele){}
    size_t size(){
        std::cout << "my_vector size is: " <<idx +1 << std::endl;
        return idx+1;
    }

    void swap(int a, int b){
        T temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    void reserve(size_t newSize){
        if(newSize > arrSize){
            resize(newSize);
        }

    }
    T front(){
        std::cout <<"the front ele is: " << arr[0] << std::endl;
        return arr[0];
    }

    T back(){
        if(idx >= 0){
            std::cout << "the last ele is: "  << arr[idx] << std::endl;
            return arr[idx];
        }else{
            throw std::out_of_range("my_vector is empty");
        }

    }
    void erase(int a){
        if( a >=0 && a <= idx){
            for(int i = a; i<= idx; i++){
                arr[i] = arr[i+1];
            }
            idx -= 1;
        }else{
            std::cout << "invalid operate" << std::endl;
        }
    }
    void erase(int a, int b){
        if(a>= 0 && b <= idx && a <= b){
            int numToErase = b - a + 1;
            for(int i= a; i + numToErase <= idx; i++){
                arr[i] = arr[i+numToErase];
            }
            idx -= numToErase;
        }else{
            std::cout << "invalid range for erase" << std::endl;
        }
    }
    void clear(){
        idx = -1;
        std::cout << "cleared" <<std::endl;
    }
    void pop_back(){
        std::cout << "removed " << arr[idx] << std::endl;
        idx -= 1;
    }
};
#endif //CPLUS_STL_MY_VECTOR_H