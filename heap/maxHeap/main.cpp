//
// Created by Tommy on 2019-11-06.
//
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
 *  大顶堆
 */
template <class Item>
class MaxHeap{
private:
    Item* data; // Item 为数据类型
    int count;
public:
    MaxHeap(int capacity){
        data = new Item[capacity+1]; //创建 item 类型的数组
        count = 0;
    }
    int size(){
        return count;
    }
    bool isEmpty(){
        return  0==count;
    }

    ~MaxHeap(){
        delete [] data;
    }
};
int main(){
    MaxHeap<int> maxHeap  =MaxHeap<int>(100);
    cout<< maxHeap.size()<<endl;
    return 0;
}