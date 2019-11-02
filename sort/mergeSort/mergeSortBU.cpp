//
// Created by Tommy on 2019-11-03.
//


#include <iostream>
#include <algorithm>
#include <string>

#include "../SortTestHelper.h"
/*
 * 自底向上
 */
template<class T>
void __merge(T arr[], int l, int mid, int r) {
    T temp[r - l + 1]; //[l ... r]
    for (int i = l; i <= r; i++) {
        temp[i - l] = arr[i];// i 从 l 开始 // 第一次循环： l-l = 0 =>arr[0]
        // 因为 arr 存储类型不定，temp 又必须赋初值，所以填充 arr[i]
    }
    int leftIndex = l, rightIndex = mid + 1;
    for (int k = leftIndex; k <= r; k++) { //k 从 [l...r]
        if (leftIndex > mid) {
            arr[k] = temp[rightIndex - l];
            rightIndex++;
        } else if (rightIndex > r) {
            arr[k] = temp[leftIndex - l];
            leftIndex++;
        } else if (temp[leftIndex - l] < temp[rightIndex - l]) {
            arr[k] = temp[leftIndex - l];
            leftIndex++;
        } else {
            arr[k] = temp[rightIndex - l];
            rightIndex++;
        }
    }

}


template <class T>
void mergeSortBU (T arr[] , int n){
    for (int size = 1; size < n; size+=size ) {
        for (int i = 0; i +size< n; i+=size+size) {
            //[i...i+size-1]  [i+size ... i+2*size -1]
            __merge(arr,i,i+size-1, min(i+size+size-1,n-1) );
        }
    }
}
int main(){
    return 0;
}

