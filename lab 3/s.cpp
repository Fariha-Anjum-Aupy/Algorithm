#include <bits/stdc++.h>
using namespace std;

int count2 = 0, count1 = 0, count3 = 0, count4 = 0;

int binarySearchRecursive(vector<int> &v, int low, int high, int x){
    count2 += 2;
    if (high >= low){
        int mid = low + (high - low) / 2;
        if (v[mid] == x) return mid;
        if (v[mid] > x) return binarySearchRecursive(v, low, mid - 1, x);
        return binarySearchRecursive(v, mid + 1, high, x);
    }
    return -1;
}

int binarySearchIterative(vector<int> &v, int low, int high, int x){
    while (low <= high){
        count3++;
        int mid = low + (high - low) / 2;
        if (v[mid] == x) return mid;
        if (v[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int linearSearchRecursive(vector<int> &v, int idx, int key){
    if (idx >= v.size()) return -1;
    count4++;
    if (v[idx] == key) return idx;
    return linearSearchRecursive(v, idx + 1, key);
}

int linearSearch(vector<int> &v, int key){
    for (int i = 0; i < v.size(); i++){
        count1 += 2;
        if (v[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    ifstream file("input1.txt");
    if (file.is_open()){
        int t;
        file >> t;
        
        cout << "Number of Inputs       Linear (Iter)\t\tLinear (Rec)\tBinary (Rec)\t\tBinary (Iter)" << endl;

        while (t--){
            int n;
            file >> n;
            vector<int> v1(n);
            for (int i = 0; i < n; i++){
                file >> v1[i];
            }

            int x;
            file >> x;

            sort(v1.begin(), v1.end());
            count1 = count2 = count3 = count4 = 0;

            // Linear search (iterative)
            int result1 = linearSearch(v1, x);

            // Linear search (recursive)
            int result4 = linearSearchRecursive(v1, 0, x);

            // Binary search (recursive)
            int result2 = binarySearchRecursive(v1, 0, n - 1, x);

            // Binary search (iterative)
            int result3 = binarySearchIterative(v1, 0, n - 1, x);

            cout << n << "\t\t\t" << count4 << "\t\t\t" << count1 
                 << "\t\t\t" << count2 << "\t\t\t" << count3 << endl;
        }
    }
    file.close();

    return 0;
}