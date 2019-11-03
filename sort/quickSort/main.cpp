//
// Created by Tommy on 2019-11-03.
//

#include <iostream>
#include <algorithm>
#include <string>

#include "../SortTestHelper.h"
// arr[l...p-1] arr[p] arr[p+1...r]
template <class T>
int  __partition(T arr[], int l , int r ){
    T v = arr[l];
    //    arr[l+1 ... j] < v < arr[j+1 ...i)
    int j =l;
    for (int i = l+1; i <= r ; i++) {
        if(arr[i]<v){
            swap(arr[j+1],arr[i]);
            j++;
        }
    }
    swap(arr[l],arr[j]);
    return j;
}

template <class T>
int  __partition2(T arr[], int lef tBound , int rightBound){
    T pivot = arr[leftBound];
    int leftIndex = leftBound+1;
    int rightIndex = rightBound;

    while (leftIndex < rightIndex){
        while(arr[leftIndex] <= pivot && leftIndex <= rightIndex){
            leftIndex ++;
        }
        while (arr[rightIndex] > pivot && leftIndex <= rightIndex){
            rightIndex++;
        }
        if(leftIndex< rightIndex){
            swap(arr[leftIndex], arr[rightIndex])
        }
    }
    // pivot move
//    swap(arr[rightIndex],arr[leftBound]);
    swap(arr[rightIndex],pivot);
    return rightIndex;

}

//[l...r]
template <class T>
void __quickSort(T arr[],int l, int r){
    if(l >= r)return;
    int p = __partition2(arr,l,r);
    __quickSort(arr, l, p-1);
    __quickSort(arr,p+1,r);
}
template <class T>
void quickSort(T arr[], int n){
    __quickSort(arr,0, n-1);
}

int main(){
    int n = 10;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::printArray(arr, n);
    cout << "======" << endl;
    SortTestHelper::testSort("quickSort", quickSort, arr, n);
    SortTestHelper::printArray(arr, n);

    delete[] arr;
    return 0;
}