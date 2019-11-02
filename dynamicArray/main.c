#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArray.h"

void test01(){
    Dynamic_Array * arr = init_arr();
    printf("capacity : %d \n", capacity_arr(arr));
    printf("size : %d \n", size_arr(arr));
    for (int i = 0; i < 30; i++) {
        push_arr(arr,i);
    }
    print_arr(arr);
    printf("capacity : %d \n", capacity_arr(arr));
    printf("size : %d \n", size_arr(arr));
    removeByIndex_arr(arr,0);
    removeByValue_arr(arr,29);
    print_arr(arr);
    int pos =  find_arr(arr,18);
    printf("No.%d => %d",pos,at_arr(arr, pos));
    freeSpace_arr(arr);
}
int main(){
    test01();
    return 0;
}