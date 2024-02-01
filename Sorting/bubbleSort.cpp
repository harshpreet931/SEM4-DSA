//
// Created by HARSHPREET SINGH on 22/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

void bubble(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size()-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main() {
    vector<int> arr = {10,9,8,7,6,5,4,3,2,1};
    bubble(arr);
    for(int i : arr) cout << i << " ";
    cout << endl;
    return 0;
}