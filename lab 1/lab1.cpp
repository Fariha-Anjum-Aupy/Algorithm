#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int dp[N];
int count1 = 0, count2 = 0;

int recursive(int n){
    count1++;
    if (n <= 1) return n;

    if (dp[n] != -1) return dp[n];

    return dp[n] = recursive(n - 1) + recursive(n - 2);
}

int iterative(int n){
    count2++;
    if (n <= 1){
        count2++;
        return n;
    }

    int a = 0, b = 1, fib = 1;
    count2 += 3;

    for (int i = 2; i <= n; i++){
        count2++;
        fib = a + b;
        count2++;

        a = b;
        b = fib;
        count2 += 2;
    }

    count2++;
    return fib;
}

int main(){
    memset(dp, -1, sizeof(dp));

    freopen("./fibonacci.txt", "r", stdin);

    int n;
    cin >> n;
    cout << "Total numbers: " << n << endl;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++){
        cout << "Number: " << arr[i] << endl;

        memset(dp, -1, sizeof(dp));
        
        count1 = 0;
        int ans1 = recursive(arr[i]);
        cout << "Total steps for recursive method: " << count1 << endl;

        count2 = 0; 
        int ans2 = iterative(arr[i]);
        cout << "Total steps for non-recursive method: " << count2 << endl;
        cout << endl;
    }

    return 0;
}