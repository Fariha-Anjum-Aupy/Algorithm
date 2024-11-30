#include <bits/stdc++.h>
#include <time.h>
using namespace std;

void generateTestCases(const string& filename) {
    ofstream outfile(filename);
    if (!outfile) {
        cerr << "Error opening file for writing test cases!" << endl;
        return;
    }

    vector<int> sizes = {50000, 100000, 200000, 300000, 500000};
    for (int size : sizes) {
        outfile << size << endl;
        for (int i = 0; i < size; i++) {
            outfile << rand() % 1000000 << endl;
        }
    }

    outfile.close();
    cout << "Test cases generated in " << filename << endl;
}

void merge(vector<int>& vec, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftVec(n1), rightVec(n2);

    for (i = 0; i < n1; i++)
        leftVec[i] = vec[left + i];
    for (j = 0; j < n2; j++)
        rightVec[j] = vec[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftVec[i] <= rightVec[j]) {
            vec[k] = leftVec[i];
            i++;
        } else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = rightVec[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& vec, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}

int partition(vector<int>& vec, int low, int high) {
    int pivot = vec[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    swap(vec[i + 1], vec[high]);
    return (i + 1);
}

void quickSort(vector<int>& vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

void runSortingAlgorithms(const string& filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file for reading test cases!" << endl;
        return;
    }

    int n;
    while (infile >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            infile >> a[i];
        }

        vector<int> copy;
        cout << "Total numbers: " << n << endl;

        copy = a;
        clock_t t1 = clock();
        mergeSort(copy, 0, n - 1);
        clock_t t2 = clock() - t1;
        cout << "Merge Sort Time: " << (float)t2 / CLOCKS_PER_SEC << " seconds" << endl;

        copy = a;
        clock_t t3 = clock();
        quickSort(copy, 0, n - 1);
        clock_t t4 = clock() - t3;
        cout << "Quick Sort Time: " << (float)t4 / CLOCKS_PER_SEC << " seconds" << endl << endl;
    }

    infile.close();
}

int main() {
    const string filename = "test.txt";

    generateTestCases(filename);
    runSortingAlgorithms(filename);

    return 0;
}