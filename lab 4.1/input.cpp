#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateCase() {
    // Set the sizes of the arrays
    vector<int> ns = {1000, 5000, 10000, 50000, 100000};
    int t = ns.size();
    
    // Open the output file
    ofstream file("input1.txt");
    if (file.is_open()) {
        file << t << "\n";  // Write the number of test cases
        
        // Seed the random number generator
        srand(time(0));
        
        // Generate each test case
        for (int i = 0; i < t; ++i) {
            int n = ns[i];
            file << n << "\n";  // Write the size of the array
            
            // Generate an array of random numbers between 1 and 100000
            vector<int> array(n);
            for (int j = 0; j < n; ++j) {
                array[j] = rand() % 100000 + 1;
            }
            
            // Write the array to the file
            for (int j = 0; j < n; ++j) {
                file << array[j] << " ";
            }
            file << "\n";
            
            // Choose a random element 'x' from the array
            int x = array[rand() % n];
            
            // Randomly select either 'x' or another number 'y'
            int y = rand() % 100000 + 1;
            int z = rand() % 100 + 1;  // Random number between 1 and 100
            file << (z <= 70 ? x : y) << "\n";
        }
    }
    file.close();
}

int main() {
    generateCase();
    cout << "Test cases generated and saved to 'input1.txt'" << endl;
    return 0;
}
