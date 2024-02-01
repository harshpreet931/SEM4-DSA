//
// Created by HARSHPREET SINGH on 1/02/2024.
//


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int count = 0;
    while(n!=0){
        n = n & n-1;
        count++;
    }
    cout << count;

//    Sir way
//    while(n){
//        if(n&1==1){
//            count++;
//        }
//        n = n >> 1;
//    }

    return 0;
}