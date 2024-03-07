//
// Created by HARSHPREET SINGH on 7/02/2024.
//
#include <bits/stdc++.h>
using namespace std;

vector<int> subset;
void solve(int a[], int n, int index) {
    if(index == n){
        // print the subset
        for(int i=0; i<subset.size(); i++){
            cout << subset[i] << " ";
        }
        cout << "\n";
    }else{
        subset.push_back(a[index]);
        solve(a, n, index+1);
        subset.pop_back();
        solve(a, n, index+1);
    }
}

int main() {
    int a[] = {1, 2, 3};
    int n = sizeof(a)/sizeof(a[0]);
    int startIndex = 0;
    solve(a, n, startIndex);
    return 0;
}