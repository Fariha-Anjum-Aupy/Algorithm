#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono> 
using namespace std;
using namespace chrono;


void generateRandomNumbersFile(const string &filename, int n) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        srand(time(0)); 
        for (int i = 0; i < n; i++) {
            outFile << rand() % 10000 << " "; 
        }
        outFile.close();
    } else {
        cerr << "Error: Unable to create the file " << filename << endl;
    }
}


int linearSearchIterative(const vector<int> &arr, int target, int &steps) {
    steps = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        steps++; 
        if (arr[i] == target)
            return i; 
    }
    return -1; 
}


int linearSearchRecursive(const vector<int> &arr, int target, int index, int &steps) {
    steps++; 
    if (index >= arr.size())
        return -1; 
    if (arr[index] == target)
        return index; 
    return linearSearchRecursive(arr, target, index + 1, steps);
}


int binarySearchIterative(const vector<int> &arr, int target, int &steps) {
    int left = 0, right = arr.size() - 1;
    steps = 0;
    while (left <= right) {
        steps++; 
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid; 
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; 
}


int binarySearchRecursive(const vector<int> &arr, int target, int left, int right, int &steps) {
    if (left > right)
        return -1; 
    steps++; 
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
        return mid; 
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, target, mid + 1, right, steps);
    else
        return binarySearchRecursive(arr, target, left, mid - 1, steps);
}

int main() {
    
    ofstream resultsFile("search_results.txt");
    if (!resultsFile.is_open()) {
        cerr << "Error: Unable to create results file.\n";
        return 1;
    }

    
    vector<int> testSizes = {1000, 2000, 3000, 4000, 5000};

    resultsFile << "Size\tLinear Iterative (Time, Steps)\tLinear Recursive (Time, Steps)\t"
                   "Binary Iterative (Time, Steps)\tBinary Recursive (Time, Steps)\n";

    for (int n : testSizes) {
       
        string inputFile = "random_numbers_" + to_string(n) + ".txt";
        generateRandomNumbersFile(inputFile, n);

        
        ifstream inFile(inputFile);
        vector<int> arr;
        int num;
        while (inFile >> num) {
            arr.push_back(num);
        }
        inFile.close();

        
        sort(arr.begin(), arr.end());

       
        int target = arr[arr.size() / 2]; 

       
        int linearIterativeSteps = 0;
        auto start = high_resolution_clock::now();
        linearSearchIterative(arr, target, linearIterativeSteps);
        auto end = high_resolution_clock::now();
        double linearIterativeTime = duration<double, milli>(end - start).count();

        
        int linearRecursiveSteps = 0;
        start = high_resolution_clock::now();
        linearSearchRecursive(arr, target, 0, linearRecursiveSteps);
        end = high_resolution_clock::now();
        double linearRecursiveTime = duration<double, milli>(end - start).count();

       
        int binaryIterativeSteps = 0;
        start = high_resolution_clock::now();
        binarySearchIterative(arr, target, binaryIterativeSteps);
        end = high_resolution_clock::now();
        double binaryIterativeTime = duration<double, milli>(end - start).count();

        
        int binaryRecursiveSteps = 0;
        start = high_resolution_clock::now();
        binarySearchRecursive(arr, target, 0, arr.size() - 1, binaryRecursiveSteps);
        end = high_resolution_clock::now();
        double binaryRecursiveTime = duration<double, milli>(end - start).count();
resultsFile << n << "\t(" << linearIterativeTime << " ms, " << linearIterativeSteps << " steps)\t"
                    << "(" << linearRecursiveTime << " ms, " << linearRecursiveSteps << " steps)\t"
                    << "(" << binaryIterativeTime << " ms, " << binaryIterativeSteps << " steps)\t"
                    << "(" << binaryRecursiveTime << " ms, " << binaryRecursiveSteps << " steps)\n";

        cout << "Search tests for n = " << n << " completed.\n";
    }

    resultsFile.close();
    cout << "Results have been written to 'search_results.txt'.\n";
    return 0;
}