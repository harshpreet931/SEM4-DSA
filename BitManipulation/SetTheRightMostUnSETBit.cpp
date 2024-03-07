//
// Created by HARSHPREET SINGH on 1/02/2024.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    if((n&(n+1))==0) cout <<  n;
    int ans = n | (n+1);
    cout << ans;
}