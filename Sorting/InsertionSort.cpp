//
// Created by HARSHPREET SINGH on 22/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

void insertion(vector<int>& arr){
    for(int i=1;i<arr.size();i++){
        int j = i - 1;
        int curr = arr[i];
        while(j>=0 && curr < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
}

int main() {
    vector<int> arr = {10,9,8,7,6,5,4,3,2,1};
    insertion(arr);
    for(int i : arr) cout << i << " ";
    return 0;
}