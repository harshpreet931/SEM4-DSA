//
// Created by HARSHPREET SINGH on 9/02/2024.
//
#include <bits/stdc++.h>
using namespace std;

void lexicographicallyorder(int n, int num){
    if(num > n) return;
    cout << num << endl;
    for(int i=0;i<10;i++){
        lexicographicallyorder(n,num*10+i);
    }
}

int main() {
    for(int i=1;i<=9;i++)
    lexicographicallyorder(100,i);
    return 0;
}