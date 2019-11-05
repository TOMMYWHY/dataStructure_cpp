//
// Created by Tommy on 2019-11-03.
//

#include <iostream>
#include <algorithm>
#include <string>

#include "../SortTestHelper.h"

/*
 * 近乎有序时，不如 merge
 * 重复项多时，效率低，On2
 *
 */
// arr[l...p-1] arr[p] arr[p+1...r]
template<class T>
int __partition(T arr[], int l, int r) {
    T v = arr[l];
    //    arr[l+1 ... j] < v < arr[j+1 ...i)
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] < v) {
            swap(arr[j + 1], arr[i]);
            //交换原理：43min  https://www.bilibili.com/video/av73598119/?p=4
            j++;
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

/*
 * 优化
 */
template<class T>
int __partitionPro(T arr[], int l, int r) {
    swap(arr[l], arr[rand() % (r - l + 1) + l]); // 随机交换
    T v = arr[l]; // pivot
    // arr[l+1...i) <= v <= arr[j...r]
    int i = l + 1, j = r;
    while (true) {
        while (arr[i] < v && i <= r) {
            i++;
        }
        while (arr[j] > v && j >= l + 1) {
            j--;
        }
        if(i>j){
            break;
        }
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    swap(arr[l],arr[j]);
    return j;
}

/*
 *  三路快排
 */
template<class T>
int __partition3way(T arr[], int l, int r) {

}



template<class T>
int __partition2(T arr[], int leftBound, int rightBound) {
    T pivot = arr[leftBound];
    int leftIndex = leftBound + 1;
    int rightIndex = rightBound;

    while (leftIndex < rightIndex) {
        while (arr[leftIndex] <= pivot && leftIndex <= rightIndex) {
            leftIndex++;
        }
        while (arr[rightIndex] > pivot && leftIndex <= rightIndex) {
            rightIndex--;
        }
        if (leftIndex < rightIndex) {
            swap(arr[leftIndex], arr[rightIndex]);
        }
    }
    // pivot move
    swap(arr[rightIndex], arr[leftBound]);//pivot == arr[leftBound] swap 交换索引传递，不是值
    return rightIndex;

}

/*
 * 快排 最佳解决方案
 *
 * */
template<class T>
int __partition3(T arr[], int leftBound, int rightBound) {
    T mid_value = arr[leftBound];
    int low = leftBound;
    int high = rightBound;
    while (low < high) {
        while (low < high && arr[high] >= mid_value) {
            high--;
        }
        arr[low] = arr[high]; // 交换之后，low 位置的值 一定 < mid_value
        while (low < high && arr[low] < mid_value) {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = mid_value;
    return low; //返回中间mid_value 值的索引
}

//[l...r]
template<class T>
void __quickSort(T arr[], int l, int r) {
    if (l >= r)return;//optimize <15 => insertionSort
//    int p = __partition3(arr, l, r);
    int p = __partitionPro(arr, l, r);

    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
}

template<class T>
void quickSort(T arr[], int n) {
    __quickSort(arr, 0, n - 1);
}

int main() {
    int n = 10;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::printArray(arr, n);
    cout << "======" << endl;
    SortTestHelper::testSort("quickSort", quickSort, arr, n);
    SortTestHelper::printArray(arr, n);

    delete[] arr;
    return 0;
}