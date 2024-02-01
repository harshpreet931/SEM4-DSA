//
// Created by HARSHPREET SINGH on 1/02/2024.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; int i;
    cin >> n >> i;
    int mask = 1 << i;
    n = n | mask;
    cout << n << endl;
    return 0;
}