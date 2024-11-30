#include<bits/stdc++.h>
using namespace std;

int crossProd(const pair<int,int>&A, const pair<int,int>&B, const pair<int,int>&C){
    return (B.first-A.first)*(C.second-A.second)-(B.second-A.second)*(C.first-A.first);
}

int distFromLine(const pair<int,int>&A, const pair<int,int>&B, const pair<int,int>&C){
    return abs(crossProd(A, B, C));
}

void recHull(const pair<int,int>&A, const pair<int,int>&B, vector<pair<int,int> >&s, vector<pair<int,int> >&h){
    if(s.empty()){
        return;
    }

    pair<int,int>farthest=s[0];
    int maxDist=distFromLine(A, B, farthest);
    for(size_t i=1; i<s.size(); i++){
        int dist=distFromLine(A, B, s[i]);
        if(dist>maxDist){
            farthest=s[i];
            maxDist=dist;
        }
    }

    h.push_back(farthest);

    vector<pair<int,int> >newSubset;
    for(size_t i=0; i<s.size(); i++){
        if(s[i]!=farthest){
            newSubset.push_back(s[i]);
        }
    }

    vector<pair<int,int> > s1,s2;
    for(size_t i=0; i<newSubset.size(); i++){
        if(crossProd(A, farthest, newSubset[i]) > 0){
            s1.push_back(newSubset[i]);
        }
        if(crossProd(farthest, B, newSubset[i]) > 0){
            s2.push_back(newSubset[i]);
        }
    }

    recHull(A, farthest, s1, h);
    recHull(farthest, B, s2, h);
}

vector<pair<int,int> >quickHull(vector<pair<int,int> >& p){
    if(p.size()<3){
        return p;
    }

    pair<int,int> left=*min_element(p.begin(), p.end());
    pair<int,int> right=*max_element(p.begin(), p.end());
    vector<pair<int,int> > h;
    h.push_back(left);
    h.push_back(right);

    vector<pair<int,int> >lSet,rSet;
    for(size_t i=0; i<p.size(); i++){
        if(crossProd(left, right, p[i]) > 0){
            lSet.push_back(p[i]);
        } 
        else if(crossProd(left, right, p[i]) < 0){
            rSet.push_back(p[i]);
        }
    }

    recHull(left, right, lSet, h);
    recHull(right, left, rSet, h);

    return h;
}

vector<pair<int,int> > readPointsFromFile(const string& f){
    ifstream file(f.c_str());
    vector<pair<int,int> > p;
    int x, y;
    while(file >> x >> y) {
        p.push_back(make_pair(x, y));
    }
    return p;
}

void generateRandomPointsToFile(int n, int xR, int yR, const string& f) {
    ofstream file(f.c_str());
    for (int i = 0; i < n; i++) {
        int x = rand() % xR + 1;
        int y = rand() % yR + 1;
        file << x << " " << y << endl;
    }
    file.close();
}

int main(){

    cout << "Quick Hull:" << endl;
    srand(time(0));

    vector<int> pCounts;
    pCounts.push_back(1000);
    pCounts.push_back(5000);
    pCounts.push_back(10000);
    pCounts.push_back(150000);

    for (size_t i = 0; i < pCounts.size(); i++) {
        int n = pCounts[i];

        ostringstream fileNameStream;
        fileNameStream << "quick_" << n << ".txt";
        string f = fileNameStream.str();

        generateRandomPointsToFile(n, 1000, 1000, f);

        vector<pair<int, int> > p = readPointsFromFile(f);

        clock_t start = clock();

        vector<pair<int, int> > h = quickHull(p);

        clock_t end = clock();

        cout << "Convex Hull for " << n << " points:" << endl;
        for (size_t j = 0; j < h.size(); j++) {
            cout << "(" << h[j].first << ", " << h[j].second << ") ";
        }

        double duration = double(end - start) / CLOCKS_PER_SEC * 1000;
        cout << "\nTime taken: " << duration << " ms\n" << endl;
    }

    return 0;
}
