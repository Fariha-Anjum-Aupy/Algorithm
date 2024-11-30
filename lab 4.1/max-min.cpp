#include <bits/stdc++.h> 
using namespace std;

void generateRandomData(const string &filename, int n){
    ofstream file(filename);
    vector<int> data;
    for (int i = 0; i < n; i++){
        data.push_back(rand() % 50000 + 1);
    }
    for (int i = 0; i < n; i++){
        file << data[i] << " ";
    }
    file.close();
}

vector<int> readFile(const string &filename){
    vector<int> data;
    ifstream file(filename);
    int value;
    while (file >> value)
    {
        data.push_back(value);
    }
    file.close();
    return data;
}

pair<int, int> MaxMin(const vector<int> &data, int n){
    int MaxElement = data[0];
    int MinElement = data[0];
    for (int i = 1; i < n; i++)
    {
        if (MaxElement < data[i])
        {
            MaxElement = data[i];
        }
        else if (MinElement > data[i])
        {
            MinElement = data[i];
        }
    }
    return make_pair(MaxElement, MinElement);
}

int main(){
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    string filename = "random_values.txt";
    generateRandomData(filename, n);
    vector<int> data = readFile(filename);

    auto start = chrono::high_resolution_clock::now();
    pair<int, int> result = MaxMin(data, n);
    auto end = chrono::high_resolution_clock::now();

    auto time = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "Maximum element : " << result.first << endl;
    cout << "Minimun element : " << result.second << endl;
    cout << "Time taken by Max and Min : " << time << " microseconds" << endl;
    return 0;
}
