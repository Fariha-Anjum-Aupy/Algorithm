#include<bits/stdc++.h>
#include <time.h>
using namespace std; 

void bubbleSort(int array[], int size){
  for (int step = 0; step < size - 1; step++){
    for (int i = 0; i < size - step - 1; i++){
      if (array[i] > array[i + 1]) {
        int temp = array[i]; 
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; ++i){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) { 
    int i, j, min_idx; 
    for (i = 0; i < n - 1; i++){  
        min_idx = i; 
        for (j = i + 1; j < n; j++){ 
            if (arr[j] < arr[min_idx]) 
                min_idx = j; 
        }  
        if (min_idx != i) swap(arr[min_idx], arr[i]); 
    } 
}

int main()
{
    freopen ("./test.txt" , "r" , stdin);

    int n;
    cin >> n;

    int originalArr[n];
    for (int i = 0; i < n; i++){
        cin >> originalArr[i];
    }

    int arr[n];

    cout << "Total numbers: " << n << endl;

    clock_t t1, t2;

    memcpy(arr, originalArr, sizeof(originalArr));
    t1 = clock();
    bubbleSort(arr, n);
    t2 = clock() - t1;
    cout << "Bubble Sort: " << (float)t2 / CLOCKS_PER_SEC << " seconds" << endl;

    clock_t t3, t4;

    memcpy(arr, originalArr, sizeof(originalArr));
    t3 = clock();
    selectionSort(arr, n);
    t4 = clock() - t3;
    cout << "Selection Sort: " << (float)t4 / CLOCKS_PER_SEC << " seconds" << endl;

    clock_t t5, t6;

    memcpy(arr, originalArr, sizeof(originalArr));
    t5 = clock();
    insertionSort(arr, n);
    t6 = clock() - t5;
    cout << "Insertion Sort: " << (float)t6 / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}