#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<double, int> a, pair<double, int> b){
    return a.first > b.first;
}

pair<double, vector<double>> knapsack(int cap, const vector<int> &w, const vector<int> &p){
    int n = w.size();
    vector<pair<double, int>> ppw(n);  // 1st = pr to wt ratio, 2nd = ind
    vector<double> frac(n, 0.0);

    for(int i = 0; i < n; ++i){
        ppw[i] = make_pair((double)p[i] / w[i], i);
    }

    sort(ppw.begin(), ppw.end(), cmp);

    double maxProfit = 0.0;
    for (int i = 0; i < n; ++i){
        int idx = ppw[i].second;
        if (cap > 0 && w[idx] <= cap){
            cap -= w[idx];
            maxProfit += p[idx];
            frac[idx] = 1.0;
        }
        else{
            frac[idx] = (double)cap / w[idx];
            maxProfit += ppw[i].first * cap;
            break;
        }
    }

    return make_pair(maxProfit, frac);
}

int main(){
    ifstream file("input.txt");

    int capacity = 20;
    int n;
    file >> n;

    vector<int> weight(n), profit(n);

    for (int j = 0; j < n; j++){
        file >> weight[j]; 
    }
    for (int j = 0; j < n; j++){
        file >> profit[j];
    }

    pair<double, vector<double>> result = knapsack(capacity, weight, profit);
    double maxProfit = result.first;
    vector<double> frac = result.second;
    
    cout << "Optimal profit: " << maxProfit << endl;
    cout << "Fraction of each item taken:" << endl;
    for (int i = 0; i < n; ++i){
        cout << "Item " << i + 1 << ": " << frac[i] << endl;
    }
}