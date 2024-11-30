#include<bits/stdc++.h>
#include <time.h>
using namespace std; 

int stepBubble = 0, stepInsertion = 0, stepSelection = 0;

void bubbleSort(int copy[], int size){
    for (int step = 0; step < size - 1; step++){
        for (int i = 0; i < size - step - 1; i++){
            stepBubble++;
            if (copy[i] > copy[i + 1]){
                swap(copy[i], copy[i + 1]);
                stepBubble++;
            }
        }
    }
}

void insertionSort(int copy[], int n){
    for(int i = 1; i < n; i++){
        int key = copy[i];
        int j = i - 1;

        while(j >= 0 && copy[j] > key){
            stepInsertion++;
            copy[j + 1] = copy[j];
            j = j - 1;
            stepInsertion++;
        }
        copy[j + 1] = key;
    }
}

void selectionSort(int copy[], int n){ 
    for (int i = 0; i < n - 1; i++){  
        int min_idx = i; 
        for (int j = i + 1; j < n; j++){
            stepSelection++;
            if (copy[j] < copy[min_idx]) 
                min_idx = j;
        }  
        if (min_idx != i){
            swap(copy[min_idx], copy[i]);
            stepSelection++;
        }
    } 
}

int main()
{
    freopen ("./test.txt" , "r" , stdin);
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int copy[n];
    cout << "Total numbers: " << n << endl;
    cout << endl; 

    memcpy(copy, a, sizeof(a));
    clock_t t1 = clock();
    bubbleSort(copy, n);
    clock_t t2 = clock() - t1;
    cout << "Bubble Sort Time: " << (float)t2 / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "Bubble Sort Steps: " << stepBubble << endl;
    cout << endl;

    memcpy(copy, a, sizeof(a));
    clock_t t3 = clock();
    selectionSort(copy, n);
    clock_t t4 = clock() - t3;
    cout << "Selection Sort Time: " << (float)t4 / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "Selection Sort Steps: " << stepSelection << endl;
    cout << endl;

    memcpy(copy, a, sizeof(a));
    clock_t t5 = clock();
    insertionSort(copy, n);
    clock_t t6 = clock() - t5;
    cout << "Insertion Sort Time: " << (float)t6 / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "Insertion Sort Steps: " << stepInsertion << endl;
    cout << endl;

    return 0;
}