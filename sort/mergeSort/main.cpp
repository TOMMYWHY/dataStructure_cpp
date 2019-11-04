//
// Created by Tommy on 2019-11-03.
//
#include <iostream>
#include <algorithm>
#include <string>

#include "../SortTestHelper.h"

/*
 * merge sort
 */
// arr[l... mid]  arr[mid+1 ...r]
template<class T>
void __merge(T arr[], int l, int mid, int r) {
    T temp[r - l + 1]; //[l ... r]
    for (int i = l; i <= r; i++) {
        temp[i - l] = arr[i];// i 从 l 开始 // 第一次循环： l-l = 0 =>arr[0]
        // 因为 arr 存储类型不定，temp 又必须赋初值，所以填充 arr[i]
    }
    int leftIndex = l, rightIndex = mid + 1;//两个数组 分别的头指针
    for (int k = l; k <= r; k++) { //k 从 [l...r] temp 的指针
        if (leftIndex > mid) {
            arr[k] = temp[rightIndex - l];// temp 对应的值 去更改 原 arr
            rightIndex++;
        } else if (rightIndex > r) {
            arr[k] = temp[leftIndex - l];
            leftIndex++;
        } else if (temp[leftIndex - l] < temp[rightIndex - l] ) { // 及 right 有余值
            arr[k] = temp[leftIndex - l];
            leftIndex++;
        } else {
            arr[k] = temp[rightIndex - l];
            rightIndex++;
        }
    }

}

template<class T>
void __mergeSort(T arr[], int leftBound, int rightBound) {
    if (leftBound >= rightBound)
        return;
    int mid = (leftBound + rightBound) / 2;
    __mergeSort(arr, leftBound, mid);//←半边数组
    __mergeSort(arr, mid + 1, rightBound); // 右半边数组

    __merge(arr, leftBound, mid, rightBound);
}

template<class T>
void mergeSort(T arr[], int n) {
    __mergeSort(arr, 0, n - 1);
}


int main() {
    int n = 20;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::printArray(arr, n);



    cout << "======"<< endl;
    SortTestHelper::testSort("mergeSort", mergeSort, arr, n);
    SortTestHelper::printArray(arr, n);

    delete[] arr;
    return 0;
}