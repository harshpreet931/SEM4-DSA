//
// Created by HARSHPREET SINGH on 27/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>arr, int k){
    int left = 0, right = 0, maxOnes = 0, zeroCount = 0;
    while(right < arr.size()){
        if(arr[right] == 0){
            zeroCount++;
        }
        while(zeroCount > k){
            if(arr[left] == 0){
                zeroCount--;
            }
            left++;
        }
        maxOnes = max(maxOnes, right-left+1);
        right++;
    }
    return maxOnes;
}

int main() {
    vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
    vector<int> arr2 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 2;
    cout << solve(arr,k);
    cout << solve(arr2,3);
    return 0;
}