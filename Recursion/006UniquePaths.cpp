//
// Created by HARSHPREET SINGH on 8/02/2024.
//
#include <bits/stdc++.h>
using namespace std;

int uniquepaths(int n, int m){
    if(n==1 || m==1) return 1;
    else return uniquepaths(n-1,m) + uniquepaths(n,m-1);
}
//SOLVE IT USING DP
int uniquePaths(int n, int m) {


}


int main() {
    cout << uniquepaths(4,3);
    cout << uniquePaths(4,3);
    return 0;
}