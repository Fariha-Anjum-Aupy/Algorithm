#include <bits/stdc++.h>
using namespace std;

// Function to generate a random integer in a given range
int getRandom(int low, int high) {
    return low + rand() % (high - low + 1);
}

int main() {
    // File to write the inputs
    ofstream file("input1.txt");
    if (!file.is_open()) {
        cerr << "Failed to open file for writing.\n";
        return 1;
    }

    // Array sizes to generate
    vector<int> sizes = {1000, 5000, 10000, 50000, 100000};

    // Number of test cases
    int t = sizes.size();
    file << t << endl;

    // Seed random number generator
    srand(time(0));

    // Generate test cases
    for (int size : sizes) {
        file << size << endl;  // Write array size

        // Generate random array elements
        for (int i = 0; i < size; ++i) {
            file << getRandom(1, 1000000) << " ";  // Random values between 1 and 1,000,000
        }
        file << endl;

        // Generate a random search element (may or may not exist in the array)
        file << getRandom(1, 1000000) << endl;
    }

    file.close();
    cout << "input1.txt file generated successfully.\n";

    return 0;
}
