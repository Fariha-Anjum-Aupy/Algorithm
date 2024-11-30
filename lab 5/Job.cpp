#include <bits/stdc++.h>
using namespace std;

const int MAX_JOBS = 105;
int profit[MAX_JOBS], deadline[MAX_JOBS];

int main(){
    ifstream input_file("jobs.txt"); 
        if (!input_file) {
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }

    int n;
    input_file >> n;

    for (int i = 0; i < n; i++){
        input_file >> profit[i]; 
    }
    for (int i = 0; i < n; i++){
        input_file >> deadline[i];
    }
    input_file.close();

    vector<int> job_indices(n);
    for (int i = 0; i < n; i++){
        job_indices[i] = i;
    }

    sort(job_indices.begin(), job_indices.end(), [](int a, int b) { return profit[a] > profit[b]; });

    int max_deadline = 0;
    for (int i = 0; i < n; i++){
        if (deadline[i] > max_deadline){
            max_deadline = deadline[i];
        }
    }
    int slots[max_deadline + 1];
    memset(slots, -1, sizeof(slots));

    int total_profit = 0;
    vector<int> selected_jobs;

    for (int i = 0; i < n; i++) {
        int job = job_indices[i];

        for (int j = deadline[job]; j > 0; j--){
            if (slots[j] == -1) {
                slots[j] = job;
                selected_jobs.push_back(job);
                total_profit += profit[job];
                break;
            }
        }
    }

    cout << "Optimal solution: " << total_profit << endl;
    cout << "Jobs selected: ";
    for (int job : selected_jobs){
        cout << job + 1 << " ";
    }
    cout << endl;

    return 0;
}
