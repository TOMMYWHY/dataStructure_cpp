#include <iostream>
#include <algorithm>
#include <string>

#include "Student.h"
#include "../SortTestHelper.h"

using namespace std;

template<class T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

int main() {
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    /* SortTestHelper::printArray(arr,n);
    selectionSort(arr, n);
    SortTestHelper::printArray(arr,n);*/
    SortTestHelper::testSort("selection sort",selectionSort, arr,n);
    delete[] arr;

    cout << "==============" << endl;

    string c[4] = {"c", "q", "a", "x"};
    selectionSort(c, 4);
    for (int i = 0; i < 4; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
    Student d[4] = {
            {"aa", 90},
            {"bb", 60},
            {"ee", 73},
            {"cc", 60}
    };
    selectionSort(d, 4);

    for (int i = 0; i < 4; i++) {
        cout << d[i];
    }

    return 0;
}