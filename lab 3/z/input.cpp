#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    ofstream outputFile("input.txt");
    
    if (!outputFile) {
        cerr << "Unable to open file for writing!" << endl;
        return 1;
    }

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    outputFile << n << endl;
    
    srand(time(0));
    
    for (int i = 0; i < n; i++) {
        outputFile << rand() % 100 + 1;  
        if (i < n - 1) outputFile << " ";  
    }

    outputFile.close();
    cout << "File 'input.txt' has been created with " << n << " random elements." << endl;

    return 0;
}
