//
// Created by HARSHPREET SINGH on 6/02/2024.
//
#include <bits/stdc++.h>
using namespace std;

int fibo(int n){
    if(n == 1) return 0;
    if(n == 2) return 1;

    return fibo(n-1) + fibo(n-2);
}

int main() {
    int n = 5;
    cout << fibo(n);
    return 0;
}