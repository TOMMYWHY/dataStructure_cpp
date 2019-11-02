//
// Created by Tommy on 2019-11-02.
//

#ifndef DATASTRUCTURE_CPP_DYNAMICARRAY_H
#define DATASTRUCTURE_CPP_DYNAMICARRAY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct DYNAMICARRAY{
    int * pAddr;
    int size;
    int capacity; //max space
}Dynamic_Array;

Dynamic_Array * init_arr();
void push_arr(Dynamic_Array * arr, int value);
void removeByIndex_arr(Dynamic_Array * arr, int position);
void removeByValue_arr(Dynamic_Array * arr, int value);
int find_arr(Dynamic_Array * arr, int value);
void freeSpace_arr(Dynamic_Array * arr);
void print_arr(Dynamic_Array * arr);

void clear_arr(Dynamic_Array * arr);
int capacity_arr(Dynamic_Array * arr);
int size_arr(Dynamic_Array * arr);
int at_arr(Dynamic_Array * arr, int position);


#endif //DATASTRUCTURE_CPP_DYNAMICARRAY_H
