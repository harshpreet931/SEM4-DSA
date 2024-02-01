//
// Created by HARSHPREET SINGH on 1/02/2024.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int count = 0;
    while(n!=0){
        n = n >> 1;
        count++;
    }
    cout << 32-count;
    return 0;
}