//
// Created by HARSHPREET SINGH on 1/02/2024.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,i;
    cin>>n>>i;
    int mask = 1 << i;
    bool ans = (n & mask);
    if(ans) cout << "set" << endl;
    else cout << "notset" << endl;
    cout << mask << endl;
    return 0;
}