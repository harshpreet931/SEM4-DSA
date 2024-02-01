//
// Created by HARSHPREET SINGH on 22/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

void selection(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        int smol = i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j] < arr[smol]){
                smol = j;
            }
        }
        swap(arr[smol],arr[i]);
    }
}

int main() {
    vector<int> arr = {10,9,8,7,6,5,4,3,2,1};
    selection(arr);
    for(int i : arr) cout << i << " ";
    return 0;
}