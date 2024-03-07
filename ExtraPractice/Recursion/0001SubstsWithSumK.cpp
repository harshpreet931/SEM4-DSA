//
// Created by HARSHPREET SINGH on 11/02/2024.
//
#include <bits/stdc++.h>
using namespace std;

void subsetswithsumK(vector<int> arr, int sum, int idx, int k, vector<int> subset){
    // base case
    if(idx == arr.size()){
        if(sum == k){
            for(int i : subset) cout << i << " ";
            cout << endl;
        }
        return;
    }

    // picking the element
    sum += arr[idx];
    subset.push_back(arr[idx]);
    subsetswithsumK(arr,sum,idx+1,k,subset);
    sum -= arr[idx];
    subset.pop_back();

    // not picking the element
    subsetswithsumK(arr,sum,idx+1,k,subset);

}

int main() {
    vector<int> arr = {1,2,1};
    int sum = 2;
    subsetswithsumK(arr,0,0,sum,{});
    return 0;
}