#include <bits/stdc++.h>
using namespace std;

int crossProd(const pair<int, int>& A, const pair<int, int>& B, const pair<int, int>& C) {
    return (B.first - A.first) * (C.second - A.second) - (B.second - A.second) * (C.first - A.first);
}

void recHull(const pair<int, int>& A, const pair<int, int>& B, vector<pair<int, int>>& s, vector<pair<int, int>>& h) {
    if (s.empty()) {
        return;
    }

    pair<int, int> farthest = s[0];
    int maxDist = abs(crossProd(A, B, farthest));
    for (size_t i = 1; i < s.size(); i++) {
        int dist = abs(crossProd(A, B, s[i]));
        if (dist > maxDist) {
            farthest = s[i];
            maxDist = dist;
        }
    }

    h.push_back(farthest);

    vector<pair<int, int>> newSubset;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] != farthest) {
            newSubset.push_back(s[i]);
        }
    }

    vector<pair<int, int>> s1, s2;
    for (size_t i = 0; i < newSubset.size(); i++) {
        if (crossProd(A, farthest, newSubset[i]) > 0) {
            s1.push_back(newSubset[i]);
        }
        if (crossProd(farthest, B, newSubset[i]) > 0) {
            s2.push_back(newSubset[i]);
        }
    }

    recHull(A, farthest, s1, h);
    recHull(farthest, B, s2, h);
}

vector<pair<int, int>> quickHull(vector<pair<int, int>>& p) {
    if (p.size() < 3) {
        return p;
    }

    pair<int, int> left = *min_element(p.begin(), p.end());
    pair<int, int> right = *max_element(p.begin(), p.end());
    vector<pair<int, int>> h;
    h.push_back(left);
    h.push_back(right);

    vector<pair<int, int>> lSet, rSet;
    for (size_t i = 0; i < p.size(); i++) {
        if (crossProd(left, right, p[i]) > 0) {
            lSet.push_back(p[i]);
        } else if (crossProd(left, right, p[i]) < 0) {
            rSet.push_back(p[i]);
        }
    }

    recHull(left, right, lSet, h);
    recHull(right, left, rSet, h);

    return h;
}

int main() {
    int n = 8;

    vector<pair<int, int>> points;

    cout << "Enter pairs of points (x y):" << endl;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    vector<pair<int, int>> hull = quickHull(points);

    cout << "Points on the convex hull:" << endl;
    for (auto i = 0; i < hull.size(); i++) {
        cout << "(" << hull[i].first << ", " << hull[i].second << ") ";
    }
    cout << endl;

    return 0;
}
