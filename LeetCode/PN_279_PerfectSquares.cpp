//
// Created by HARSHPREET SINGH on 8/02/2024.
//
#include <bits/stdc++.h>
using namespace std;

int numSquares(int n){
    vector<int> dp(n+1,n);
    dp[0] = 0;

    for(int i = 1; i<=n ;i++){
        for(int j = 1; j*j<=i;j++) {
            int sq = j * j;
            if (sq > i) break;
            dp[i] = min(dp[i], dp[i - sq] + 1);
        }
    }
    return dp[n];
}

int main() {
    cout << numSquares(12) << endl;
    return 0;
}