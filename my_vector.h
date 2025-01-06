//
// Created by admin on 2025/1/4.
//
#include <iostream>
#ifndef CPLUS_STL_MY_VECTOR_H
#define CPLUS_STL_MY_VECTOR_H
#endif //CPLUS_STL_MY_VECTOR_H
template<typename T>
class my_vector{
private:
    int idx;
    int arrSize;
    T* arr;
public:
    my_vector():idx(-1), arrSize(2), arr(new T[arrSize]){}
    ~my_vector(){
        delete[] arr;
    }

    void push_back(T ele){
        if(idx == arrSize -1){
            arrSize *= 2;
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

    //void insert(int index, T ele){}
    int size(){
        std::cout << "my_vector size is: " <<idx +1 << std::endl;
        return idx+1;
    }

    void swap(int a, int b){
        T temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    void reserve(){}
    T front(){
        std::cout <<"the front ele is: " << arr[0] << std::endl;
        return arr[0];
    }
    T back(){
        std::cout << "the last ele is: "  << arr[idx] << std::endl;

    }
    void erase(int a){
        if( a >=0 && a <= idx){
            for(int i = a; i<= idx; i++){
                arr[i] = a+1;
            }
            idx -= 1;
        }else{
            std::cout << "invalid operate" << std::endl;
        }
    }
    void erase(int a, int b){
        if(a>= 0 && b <= idx){
            int j = a;
            for(int i= b; i<= idx; i++){
                arr[j] = arr[b];
                j++;
            }
            idx -= (b-a);
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