//
// Created by HARSHPREET SINGH on 22/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

int longest(vector<int> arr, int k){
    int start = 0, end = 0;
    int sum = 0;
    int mx = 0;
    while(end < arr.size()){
        sum += arr[end];
        while(sum > k){
            sum -= arr[start];
            start++;
        }
        if(sum == k){
            mx = max(mx,end-start+1);
        }

        end++;
    }
    return mx;
}

int main() {
    vector<int> arr = {2,3,2,1,1,1,4,1,3};
    int k = 5;
    int mx = 0;
    for(int i=0;i<arr.size();i++){
        int sum = 0;
        for(int j=i;j<arr.size();j++){
            sum += arr[j];
            if(sum == k){
                mx = max(mx, j-i+1);
            }
        }
    }
    cout << mx;
    cout << longest(arr,5);
    cout << endl;
    return 0;
}