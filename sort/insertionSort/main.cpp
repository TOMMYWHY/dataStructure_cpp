//
// Created by Tommy on 2019-11-02.
//
#include <iostream>
#include <algorithm>
#include <string>

#include "../SortTestHelper.h"

template <class T>
void insertionSort(T arr[], int n){
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if(arr[j-1] > arr[j]){
                swap(arr[j-1],arr[j]);
            }else{
                break;
            }
        }
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

