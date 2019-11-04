//
// Created by Tommy on 2019-11-02.
//
#include <iostream>
#include <algorithm>
#include <string>

#include "../SortTestHelper.h"

/*
 * On2
 * 对于 近似有序数组，插排效率最高。可以高于 nlogn。
 */
template <class T>
void insertionSort(T arr[], int n){
    for (int i = 1; i < n; i++) {
        T element = arr[i]; //确定等待插入元素a
        int j; //
        for ( j = i; j > 0 && arr[j-1] > element; j--) {// 前一个 与 a 比较
                arr[j] =arr[j-1]; // 后移
        }
        arr[j] =element; // 交换
    }
}
template <class  T>
void insertionSort2(T arr[], int n){
    for (int i = 1; i < n; i++) {
        T insertValue = arr[i];
        int insertPervIndex = i -1;
        while (insertPervIndex >=0 && arr[insertPervIndex] > insertValue){
            arr[insertPervIndex +1] = arr[insertPervIndex];
            insertPervIndex --;
        }
        arr[insertPervIndex + 1] = insertValue ;
    }
}

using namespace std;

int main(){
    int n = 10;
    int * arr= SortTestHelper::generateRandomArray(n,0,n);
    int * arr2 = SortTestHelper::copyIntArray(arr,n);
    SortTestHelper::printArray(arr, n);
    cout << "======" << endl;
    SortTestHelper::testSort("insertionSort",insertionSort2,arr,n);
    SortTestHelper::printArray(arr, n);

    delete[] arr;
    delete[] arr2;
    return 0;
};

