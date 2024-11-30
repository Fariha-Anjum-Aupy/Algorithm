#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int itr(int arr[], int n, int x, int &comparisonCount){
    for (int i = 0; i < n; i++)
    {
        comparisonCount++;
        if (arr[i] == x){
            return i + 1;
        }
    }
    return -1;
}

int rec(int arr[], int n, int x, int &comparisonCount){
    if (n == 0){
        return -1;
    }

    comparisonCount++;
    if (arr[n - 1] == x){
        return n;
    }

    return rec(arr, n - 1, x, comparisonCount);
}

int main(){
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile){
        cerr << "Unable to open input file!" << endl;
        return 1;
    }
    if (!outputFile){
        cerr << "Unable to open output file!" << endl;
        return 1;
    }

    int n;
    inputFile >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        inputFile >> arr[i];
    }
    inputFile.close();

    int x;
    cout << "Enter the value to search for: ";
    cin >> x;

    int it_Count = 0;
    auto start_itr = high_resolution_clock::now();
    int itr_Result = itr(arr, n, x, it_Count);
    auto end_itr = high_resolution_clock::now();
    auto duration_itr = duration_cast<nanoseconds>(end_itr - start_itr).count();

    int rec_Count = 0;
    auto start_rec = high_resolution_clock::now();
    int rec_Result = rec(arr, n, x, rec_Count);
    auto end_rec = high_resolution_clock::now();
    auto duration_rec = duration_cast<nanoseconds>(end_rec - start_rec).count();

    outputFile << "itrative Linear Search:\n";
    if (itr_Result != -1){
        outputFile << "Element found at position " << itr_Result << endl;
    }
    else{
        outputFile << "Element not found" << endl;
    }
    outputFile << "Number of comparisons (itrative): " << it_Count << endl;
    outputFile << "Time taken (itrative): " << duration_itr << " ns" << endl;

    outputFile << "\nrecursive Linear Search:\n";
    if (rec_Result != -1){
        outputFile << "Element found at position " << rec_Result << endl;
    }
    else{
        outputFile << "Element not found" << endl;
    }
    outputFile << "Number of comparisons (rec): " << rec_Count << endl;
    outputFile << "Time taken (recursive): " << duration_rec << " ns" << endl;
    outputFile.close();
    cout << "Results have been written to output.txt" << endl;
    return 0;
}