#include "DynamicArray.h"


Dynamic_Array *init_arr() {
    Dynamic_Array* myArr = (Dynamic_Array *)malloc(sizeof(Dynamic_Array));
    myArr->size = 0;
    myArr->capacity = 20;
    myArr->pAddr = (int *)malloc(sizeof(int)*myArr->capacity);
    return myArr;
}

void push_arr(Dynamic_Array *arr, int value) {
    if(arr == NULL){
        return;
    }
    if(arr->size == arr->capacity){
        int* newSpace = (int *)malloc(sizeof(int)*arr->capacity*2);
        memcpy(newSpace, arr->pAddr,arr->capacity* sizeof(int));
        free(arr->pAddr);
        arr->capacity = arr->capacity*2;
        arr->pAddr = newSpace;
    }
    arr->pAddr[arr->size] = value;
    arr->size++;
}

void removeByIndex_arr(Dynamic_Array *arr, int position) {
    if(arr == NULL){
        return;
    }
    if(position< 0 || position >= arr->size){
        return;
    }
    for (int i = position; i < arr->size-1; i++) {
         arr-> pAddr[i] = arr->pAddr[i +1];
    }
    //i < arr->size-1 防止指针越界，可有可无。但 java 中如果不-1 崩~！
    arr->size --;
}

void removeByValue_arr(Dynamic_Array *arr, int value) {
    if(arr == NULL){
        return;
    }
    int pos = find_arr(arr,value);
    removeByIndex_arr(arr,pos);
}

int find_arr(Dynamic_Array *arr, int value) {
    if(arr == NULL){
        return -1;
    }
    int pos = -1;
    for (int i = 0; i < arr->size; i++) {
        if(arr->pAddr[i] == value){
            pos = i;
            break;
        }
    }
    return pos;
}

void freeSpace_arr(Dynamic_Array *arr) {
    if(arr == NULL){
        return;
    }
    if(arr->pAddr != NULL){
        free(arr->pAddr);
    }
    free(arr);
}

void print_arr(Dynamic_Array *arr) {
    if(arr == NULL){
        return ;
    }
    for (int i = 0; i < arr->size; i++) {
        printf("%d ",arr->pAddr[i]);
    }
    printf("\n");
}

void clear_arr(Dynamic_Array *arr) {
    if(arr == NULL){
        return ;
    }
    arr->size = 0;
}

int capacity_arr(Dynamic_Array *arr) {
    if(arr == NULL){
        return -1;
    }
    return arr->capacity;
}

int size_arr(Dynamic_Array *arr) {
    if(arr == NULL){
        return -1;
    }
    return arr->size;
}

int at_arr(Dynamic_Array *arr, int position) {

    return arr->pAddr[position];
}