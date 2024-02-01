//
// Created by HARSHPREET SINGH on 30/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> arr = {{8,10},{15,18},{2,6},{1,3}};
    sort(arr.begin(), arr.end());
    for(auto i : arr){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}