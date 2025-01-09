#pragma once //tell compiler included once


#include <vector>
#include <iostream>

template<typename T>
class my_priorityQ{
private:
    std::vector<T> maxHeap;

    void shiftUp(int index){
        while (index > 0){
            int theTop = (index-1)/2;
            if(maxHeap[theTop] >= maxHeap[index]){
                break;
            }
            std::swap(maxHeap[index], maxHeap[theTop]);
            index = theTop;
        }
    }

    void shiftDown(int index){
        int len = maxHeap.size();
        while (true){
            int largest = index;
            int left = index*2 + 1;
            int right = index*2 + 2;

            if(left < len && maxHeap[left] > maxHeap[largest]){
                largest = left;
            }
            if(right < len && maxHeap[right] > maxHeap[largest]){
                largest = right;
            }

            if(largest == index){
                break;
            }

            std::swap(maxHeap[index], maxHeap[largest]);
            index = largest;
        }

    }


public:
    void push(T& ele){
        maxHeap.push_back(ele);
        shiftUp(maxHeap.size() -1);
    }

    void pop(){
        if(maxHeap.empty()){
            throw std::out_of_range("queue is empty");
        }
        std::swap(maxHeap[0], maxHeap.back());
    }

    T& top(){
        if(maxHeap.empty()){
            throw std::out_of_range("queue is empty");
        }
        return maxHeap[0];
    }
    size_t size(){
        return maxHeap.size();
    }
    bool isEmpty(){
        return maxHeap.empty();
    }
};