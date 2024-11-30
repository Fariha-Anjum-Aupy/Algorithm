#include<bits/stdc++.h>
using namespace std;

pair<int,int>basePoint;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
    return (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);
}

int distanceSquared(int x1, int y1, int x2, int y2){
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

bool polarCompare(const pair<int, int>& p1, const pair<int, int>& p2){
    int orientation = ccw(basePoint.first, basePoint.second, p1.first, p1.second, p2.first, p2.second);
    if(orientation == 0){
        return distanceSquared(basePoint.first, basePoint.second, p1.first, p1.second) <
               distanceSquared(basePoint.first, basePoint.second, p2.first, p2.second);
    }
    return orientation > 0;
}

void convexHull(vector<pair<int, int> >&points){
    int n = points.size();
    // if(n <= 3){
    //     cout <<"Points on the convex hull:\n";
    //     for(size_t i = 0; i<points.size(); i++){
    //         cout <<"(" << points[i].first << ", " << points[i].second << ")\n";
    //     }
    //     return;
    // }

    basePoint = points[0];
    int baseIndex = 0;
    for(int i = 1; i < n; i++){
        if (points[i].second < basePoint.second || (points[i].second == basePoint.second && points[i].first < basePoint.first)) {
            basePoint = points[i];
            baseIndex = i;
        }
    }

    swap(points[0], points[baseIndex]);
    sort(points.begin()+1, points.end(), polarCompare);

    vector<pair<int,int> >hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);

    for(int i = 2; i < n; i++){
        while(hull.size()>1 &&
               ccw(hull[hull.size()-2].first, hull[hull.size()-2].second,
                   hull[hull.size()-1].first, hull[hull.size()-1].second,
                   points[i].first, points[i].second) <= 0){
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    cout <<"Points on the convex hull:" << endl;
    for(size_t i=0; i < hull.size(); i++){
        cout <<"(" << hull[i].first << ", " << hull[i].second << ") ";
    }
}

void generatePoints(int count, ofstream& outFile){
    for(int i = 0; i < count; i++){
        int x = rand()%1000;
        int y = rand()%1000; 
        outFile << x << " " << y <<" ";
    }
    outFile << endl;
}

void processPointsFromFile(const string& filename){
    ifstream inFile(filename.c_str());
    if(!inFile){
        cerr<<"Error opening file!"<<endl;
        return;
    }

    vector<pair<int,int> > points;
    int x, y;

    while(inFile >> x >> y){
        points.push_back(make_pair(x,y));
    }

    inFile.close();

    clock_t start=clock();
    convexHull(points);
    clock_t end=clock();

    double duration=double(end-start)/CLOCKS_PER_SEC * 1000; 
    cout << "\nTime taken for execution: " << duration << " ms" <<endl;
}

int main(){
    cout << "Graham Scan:" << endl;
    ofstream outFile("Graham.txt");

    if(!outFile){
        cerr << "Error opening file!" << endl;
        return 1;
    }

    generatePoints(1000, outFile);  
    generatePoints(5000, outFile);  
    generatePoints(10000, outFile); 
    generatePoints(15000, outFile);

    outFile.close();

    cout << "\nList 1 (1000 points):" << endl;
    processPointsFromFile("Graham.txt");
    cout << endl;

    cout << "\nList 2 (5000 points):" << endl;
    processPointsFromFile("Graham.txt");
    cout << endl;

    cout << "\nList 3 (10000 points):" << endl;
    processPointsFromFile("Graham.txt");
    cout << endl;

    cout << "\nList 4 (15000 points):" << endl;
    processPointsFromFile("Graham.txt");
    cout << endl;
    return 0;
}