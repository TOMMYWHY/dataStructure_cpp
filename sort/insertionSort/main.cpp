//
// Created by Tommy on 2019-11-02.
//
#include <iostream>
#include <algorithm>
#include <string>

#include "../SortTestHelper.h"

/*
 * 对于 近似有序数组，插排效率最高。可以高于 nlogn。 On
 */
template <class T>
void insertionSort(T arr[], int n){
    for (int i = 1; i < n; i++) {
        T element = arr[i]; //
        int j; // 疑似目标位置
        for ( j = i; j > 0 && arr[j-1] > element; j--) {
                arr[j] =arr[j-1]; // 后移
        }
        arr[j] =element; // 交换
    }
}

using namespace std;

int main(){
    int n = 1000;
    int * arr= SortTestHelper::generateRandomArray(n,0,n);
    int * arr2 = SortTestHelper::copyIntArray(arr,n);
    SortTestHelper::testSort("insertionSort",insertionSort,arr,n);
    delete[] arr;
    delete[] arr2;
    return 0;
};

